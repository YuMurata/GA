#include "stdafx.h"
#include "GA.h"

#include"CrossFactory.h"
#include"MutateFactory.h"

using namespace std;

GA::GA
(
	const int &population,const int &genome_size,const int &genomes_size,
	const EvalFunc &eval_func,const DispFunc &disp_func
)
	:population(population),genome_size(genome_size),genomes_size(genomes_size),
	PreEval(eval_func),PreDisp(disp_func)
{
	this->gene.reserve(population);
	auto func = [&]() {return this->GenGenome(); };
	generate_n(back_inserter(this->gene), population, func);
}


GA::~GA()
{
}

vector<Genome> GA::PreConvert(const Genome &genome)
{
	vector<Genome> genomes(this->genomes_size/this->genome_size);

	auto start = begin(genome);
	auto func = [&]()
	{
		auto last = start + this->genome_size;
		Genome ret(start, last);

		start = last;
		return ret;
	};
	generate(begin(genomes), end(genomes), func);

	return genomes;
}

Conv GA::Convert(const Genome &genome)
{
	auto genomes = PreConvert(genome);
	Conv ret(size(genomes));
	auto func=[](const Genome &i)
	{
		auto func = [](const int &left, const int &right)
		{
			auto ret = left * 2 + right;
			return ret;
		};

		auto sum = accumulate(begin(i), end(i), 0, func);
		return sum;
	};

	transform(begin(genomes), end(genomes), begin(ret), func);

	return ret;
}

double GA::Eval(const Genome &genome)
{
	auto conv = this->Convert(genome);
	auto eval = this->PreEval(conv);

	return eval;
}

Genome GA::GenGenome()
{
	Genome genome(this->genomes_size);
	auto func = [&]()
	{
		auto ret = this->rand<uniform_int_distribution<>>(0,1);
		return ret;
	};
	generate(begin(genome), end(genome), func);

	return genome;
}

GenomeList GA::NextGene(const GenomeList &old_gene)
{
	vector<double> evals;
	evals.reserve(population);

	for (auto &i : old_gene)
	{
		evals.push_back(Eval(i));
	}

	GenomeList ret;
	ret.reserve(population);
	auto max_index = distance(begin(evals), max_element(begin(evals), end(evals)));
	ret.push_back(old_gene[max_index]);

	discrete_distribution<> dist(begin(evals), end(evals));
	
	CrossFactory cross_obj(this->genomes_size);
	MutateFactory mutate_obj(this->genomes_size);

	while (size(ret) < population)
	{
		GenomeList children;

		auto &f = old_gene[dist(this->mt)];
		auto &m = old_gene[dist(this->mt)];

		children = cross_obj.Cross(f, m);

		if (this->rand<uniform_int_distribution<>>(0,100) <30 )
		{
			children = mutate_obj.Mutate(children);
		}

		ret.insert(end(ret), begin(children), end(children));
	}

	return ret;
}

void GA::Disp(const GenomeList &gene)
{
	for (auto &genome : gene)
	{
		auto conv = this->Convert(genome);
		auto str = this->PreDisp(conv);
		std::cout << str << ":" << Eval(genome) << endl;
	}
}

void GA::Evolve(const double &threshold, const bool &gene_flag)
{
	double eval=0;
	auto IsFinish = [&]()
	{
		eval = gene_flag ? eval + 1 : this->Eval(this->gene[0]);
		auto ret = eval > threshold;
		return ret;
	};
	while (!IsFinish())
	{
		cout << "--------------------" << endl;
		Disp(gene);
		gene = NextGene(gene);
		//++generation_num;
	}
}
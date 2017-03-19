#include "stdafx.h"
#include "GA.h"

#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<memory>
#include<string>

#include"Cross.h"

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

GenomeList GA::MutaGenome(const GenomeList &genomes)
{
	GenomeList ret = genomes ;
	for (auto &i : ret)
	{
		for (int j = 0; j < (this->genomes_size >> 1); ++j)
		{
			auto index1 = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);
			auto index2 = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);

			swap(i[index1], i[index2]);
		}
	}

	return ret;
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
	
	vector<unique_ptr<CrossBase>> cross;
	cross.push_back(make_unique<PointCross>(this->genomes_size));
	cross.push_back(make_unique<UniformCross>(this->genomes_size));
	cross.push_back(make_unique<NonCross>(this->genomes_size));
	

	auto cross_num = size(cross);

	while (size(ret) < population)
	{
		GenomeList children;

		auto &f = old_gene[dist(this->mt)];
		auto &m = old_gene[dist(this->mt)];

		auto pattern = this->rand<uniform_int_distribution<>>(0, cross_num-1);
		children = cross[pattern]->Cross(f, m);

		if (this->rand<uniform_real_distribution<>>(0,1) < 0.1)
		{
			children = MutaGenome(children);
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
#pragma once


#include"GADefine.h"

class GA:public Randomer
{
private:
	const int population;
	const int genome_size;
	const int genomes_size;

	EvalFunc PreEval;
	DispFunc PreDisp;
	GenomeList gene;


public:
	GA(const int &population, const int &genome_size, const int &genomes_size, const EvalFunc &eval_func,const DispFunc &disp_func);
	~GA();


	GenomeList PreConvert(const Genome &genome);

	Conv Convert(const Genome &genome);

	double Eval(const Genome &genome);

	Genome GenGenome();

	void Evolve()
	{
		while (Eval(gene[0])<10000)
		{
			//cout << generation_num << endl;
			Disp(gene);
			gene = NextGene(gene);
			//++generation_num;
		}
	}

	GenomeList NextGene(const GenomeList &old_gene);

	void Disp(const GenomeList &gene);
};


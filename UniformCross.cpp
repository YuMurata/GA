#include "stdafx.h"
#include "UniformCross.h"

using namespace std;

UniformCross::UniformCross(const int &genomes_size):CrossBase(genomes_size)
{
}


UniformCross::~UniformCross()
{
}

GenomeList UniformCross::Cross(const Genome &father, const Genome &mother)
{
	vector<int> index(genomes_size / 2);
	generate(begin(index), end(index), [&]() {return this->rand<uniform_int_distribution<>>(0,this->genomes_size-1); });

	Genome fc = father;
	Genome mc = mother;

	for (auto &i : index)
	{
		swap(fc[i], mc[i]);
	}

	vector<Genome> ret{ fc, mc };
	return ret;
}
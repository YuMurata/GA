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

	auto itrs=mismatch(begin(fc), end(fc), begin(mc));

	while (itrs.first != end(fc))
	{
		if (this->rand<uniform_int_distribution<>>(0, 1))
		{
			swap(*itrs.first, *itrs.second);
		}
		itrs = mismatch(itrs.first+1, end(fc), itrs.second+1);
	}

	vector<Genome> ret{ fc, mc };
	return ret;
}
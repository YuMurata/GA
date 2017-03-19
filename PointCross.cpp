#include "stdafx.h"
#include "PointCross.h"

using namespace std;

PointCross::PointCross(const int &genomes_size):CrossBase(genomes_size)
{
}


PointCross::~PointCross()
{
}

GenomeList PointCross::Cross(const Genome &father, const Genome &mother)
{
	Genome fc = father;
	Genome mc = mother;

	auto index1 = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);
	auto index2 = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);

	if (index2 < index1)
	{
		swap(index1, index2);
	}

	auto fc_start = begin(fc) + index1;
	auto mc_start = begin(mc) + index1;

	auto fc_last = begin(fc) + index2;
	auto mc_last = begin(mc) + index2;

	Genome temp(fc_start, fc_last);
	copy(mc_start, mc_last, fc_start);
	copy(begin(temp), end(temp), mc_start);

	vector<Genome> ret{ fc, mc };
	return ret;
}
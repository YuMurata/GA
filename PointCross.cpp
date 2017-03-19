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

	auto index = this->rand<uniform_int_distribution<>>(0,this->genomes_size-1);
	auto fc_itr = begin(fc) + index;
	auto mc_itr = begin(mc) + index;

	Genome temp(fc_itr, end(fc));
	copy(mc_itr, end(mc), fc_itr);
	copy(begin(temp), end(temp), mc_itr);

	vector<Genome> ret{ fc, mc };
	return ret;
}
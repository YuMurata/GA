#include "stdafx.h"
#include "NonCross.h"


NonCross::NonCross(const int &genomes_size):CrossBase(genomes_size)
{
}


NonCross::~NonCross()
{
}


GenomeList NonCross::Cross(const Genome &father, const Genome &mother)
{
	Genome fc = father;
	Genome mc = mother;

	GenomeList ret{ fc, mc };
	return ret;
}
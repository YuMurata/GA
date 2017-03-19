#include "stdafx.h"
#include "SwapMutate.h"

using namespace std;

SwapMutate::SwapMutate(const int &genomes_size):MutateBase(genomes_size)
{
}


SwapMutate::~SwapMutate()
{
}


// Ž©ŒÈ“à‚Åˆâ“`Žq‚ðŒðŠ·‚·‚é
GenomeList SwapMutate::Mutate(const GenomeList& children)
{
	GenomeList ret = children;
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

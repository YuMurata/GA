#include "stdafx.h"
#include "SwapMutate.h"

using namespace std;

SwapMutate::SwapMutate(const int &genomes_size):MutateBase(genomes_size)
{
}


SwapMutate::~SwapMutate()
{
}


// ©ŒÈ“à‚Åˆâ“`q‚ğŒğŠ·‚·‚é
GenomeList SwapMutate::Mutate(const GenomeList& children)
{
	GenomeList ret = children;

	auto gen_func = [&]()
	{
		auto ret = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);
		return ret;
	};

	auto mutate_num = gen_func();

	for (auto &i : ret)
	{
		for (int j = 0; j < mutate_num; ++j)
		{
			auto index1 = gen_func();
			auto index2 = gen_func();

			swap(i[index1], i[index2]);
		}
	}

	return ret;
}

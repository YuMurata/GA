#include "stdafx.h"
#include "MutateFactory.h"

#include"SwapMutate.h"
#include"InverseMutate.h"
#include"RandomMutate.h"

#include<Builder.h>

using namespace std;

struct MutateFactory::Impl
{
	vector<unique_ptr<MutateBase>> p_mutate;
	Impl(const int &genomes_size)
	{
		this->p_mutate = VUInitialize<MutateBase>
			(
				make_unique<SwapMutate>(genomes_size),
				make_unique<InverseMutate>(genomes_size),
				make_unique<RandomMutate>(genomes_size)
				);
	}
};


MutateFactory::MutateFactory(const int &genomes_size):pimpl(make_unique<Impl>(genomes_size))
{
}


MutateFactory::~MutateFactory() = default;


GenomeList MutateFactory::Mutate(const GenomeList &children)
{
	auto index = this->rand<uniform_int_distribution<>>(0, size(this->pimpl->p_mutate) - 1);
	auto ret = this->pimpl->p_mutate[index]->Mutate(children);

	return ret;
}
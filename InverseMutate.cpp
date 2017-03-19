#include "stdafx.h"
#include "InverseMutate.h"
#include<algorithm>

using namespace std;

InverseMutate::InverseMutate(const int &genomes_size):MutateBase(genomes_size)
{
}


InverseMutate::~InverseMutate()
{
}


// ©ŒÈ“à‚Ìˆâ“`q‚ğ”½“]‚³‚¹‚é
GenomeList InverseMutate::Mutate(const GenomeList& children)
{
	GenomeList ret = children;


	auto gen_func = [&]()
	{
		auto ret=this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);
		return ret;
	};

	auto inv_func = [](const int &x)
	{
		auto ret = (x + 1) % 2;
		return ret;
	};

	auto func = [&](const Genome &i)
	{
		vector<int> index(this->genomes_size >> 1);
		generate(begin(index), end(index), gen_func);
		
		Genome ret(this->genomes_size);
		transform(begin(i), end(i), begin(ret), inv_func);

		return ret;
	};

	transform(begin(children), end(children), begin(ret), func);

	return ret;
}

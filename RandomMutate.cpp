#include "stdafx.h"
#include "RandomMutate.h"

using namespace std;

RandomMutate::RandomMutate(const int &genomes_size):MutateBase(genomes_size)
{
}


RandomMutate::~RandomMutate()
{
}


// ランダムに変異させる
GenomeList RandomMutate::Mutate(const GenomeList& children)
{
	GenomeList ret = children;


	auto gen_func = [&]()
	{
		auto ret = this->rand<uniform_int_distribution<>>(0, this->genomes_size - 1);
		return ret;
	};

	auto rand_func = [&](const int &x)
	{
		auto ret = this->rand<uniform_int_distribution<>>(0, 1);
		return ret;
	};

	auto func = [&](const Genome &i)
	{
		vector<int> index(gen_func());
		generate(begin(index), end(index), gen_func);

		Genome ret(this->genomes_size);
		transform(begin(i), end(i), begin(ret), rand_func);

		return ret;
	};

	transform(begin(children), end(children), begin(ret), func);

	return ret;
}

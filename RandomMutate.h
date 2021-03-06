#pragma once
#include "MutateBase.h"
class RandomMutate :
	public MutateBase
{
public:
	RandomMutate(const int &genomes_size);
	~RandomMutate();
	// ランダムに変異させる
	GenomeList Mutate(const GenomeList& children);
};


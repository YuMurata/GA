#pragma once
#include "MutateBase.h"
class RandomMutate :
	public MutateBase
{
public:
	RandomMutate(const int &genomes_size);
	~RandomMutate();
	// ƒ‰ƒ“ƒ_ƒ€‚É•ÏˆÙ‚³‚¹‚é
	GenomeList Mutate(const GenomeList& children);
};


#pragma once
#include "MutateBase.h"
class SwapMutate :
	public MutateBase
{
public:
	SwapMutate(const int &genomes_size);
	~SwapMutate();
	// ©ŒÈ“à‚Åˆâ“`q‚ğŒğŠ·‚·‚é
	GenomeList Mutate(const GenomeList& children);
};


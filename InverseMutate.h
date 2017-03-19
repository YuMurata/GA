#pragma once
#include "MutateBase.h"
class InverseMutate :
	public MutateBase
{
public:
	InverseMutate(const int &genomes_size);
	~InverseMutate();
	// Ž©ŒÈ“à‚Ìˆâ“`Žq‚ð”½“]‚³‚¹‚é
	GenomeList Mutate(const GenomeList& children);
};


#pragma once
#include "MutateBase.h"
class RandomMutate :
	public MutateBase
{
public:
	RandomMutate(const int &genomes_size);
	~RandomMutate();
	// �����_���ɕψق�����
	GenomeList Mutate(const GenomeList& children);
};


#pragma once
#include "MutateBase.h"
class InverseMutate :
	public MutateBase
{
public:
	InverseMutate(const int &genomes_size);
	~InverseMutate();
	// ���ȓ��̈�`�q�𔽓]������
	GenomeList Mutate(const GenomeList& children);
};


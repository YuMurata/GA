#pragma once
#include "MutateBase.h"
class SwapMutate :
	public MutateBase
{
public:
	SwapMutate(const int &genomes_size);
	~SwapMutate();
	// ���ȓ��ň�`�q����������
	GenomeList Mutate(const GenomeList& children);
};


#pragma once
#include "CrossBase.h"
class NonCross :
	public CrossBase
{
public:
	NonCross(const int &genomes_size);
	~NonCross();

	GenomeList Cross(const Genome &father, const Genome &mother)override;
};


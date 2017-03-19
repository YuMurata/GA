#pragma once
#include "CrossBase.h"
class UniformCross :
	public CrossBase
{
public:
	UniformCross(const int &genomes_size);
	~UniformCross();

	GenomeList Cross(const Genome &father, const Genome &mother)override;
};


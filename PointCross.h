#pragma once
#include "CrossBase.h"
class PointCross :
	public CrossBase
{
public:
	PointCross(const int &genomes_size);
	~PointCross();

	GenomeList Cross(const Genome &father, const Genome &mother)override;
};


#pragma once

#include"GADefine.h"
#include<Randomer.h>

class CrossBase:public Randomer
{
protected:
	const int genomes_size;
public:
	CrossBase(const int &genomes_size);
	~CrossBase();

	virtual GenomeList Cross(const Genome &father, const Genome &mother)=0;
};


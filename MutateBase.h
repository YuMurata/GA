#pragma once

class MutateBase :
	public Randomer
{
public:
	MutateBase(const int &genomes_size);
	~MutateBase();
	// “Ë‘R•ÏˆÙ
	virtual GenomeList Mutate(const GenomeList& children) = 0;
protected:
	const int genomes_size;
};


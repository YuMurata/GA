#pragma once

class MutateBase :
	public Randomer
{
public:
	MutateBase(const int &genomes_size);
	~MutateBase();
	// �ˑR�ψ�
	virtual GenomeList Mutate(const GenomeList& children) = 0;
protected:
	const int genomes_size;
};


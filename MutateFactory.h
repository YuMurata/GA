#pragma once
class MutateFactory :
	public Randomer
{
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;

public:
	MutateFactory(const int &genomes_factory);
	~MutateFactory();

	GenomeList Mutate(const GenomeList &children);
};


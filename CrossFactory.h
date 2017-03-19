#pragma once

class CrossFactory:public Randomer
{
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl;

public:
	CrossFactory(const int &genomes_size);
	~CrossFactory();

	GenomeList Cross(const Genome &father, const Genome &mother);
};
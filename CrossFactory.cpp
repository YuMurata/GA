#include"CrossFactory.h"

#include"PointCross.h"
#include"UniformCross.h"
#include"NonCross.h"

#include<Builder.h>

using namespace std;

struct CrossFactory::Impl
{
	vector<unique_ptr<CrossBase>> p_cross;
	Impl(const int &genomes_size)
	{
		this->p_cross = VUInitialize<CrossBase>
			(
				make_unique<PointCross>(genomes_size),
				make_unique<UniformCross>(genomes_size),
				make_unique<NonCross>(genomes_size)
				);
	}
};

CrossFactory::CrossFactory(const int &genomes_size) :pimpl(make_unique<Impl>(genomes_size)) {}

CrossFactory::~CrossFactory() = default;

GenomeList CrossFactory::Cross(const Genome &father,const Genome &mother)
{
	auto index = this->rand<uniform_int_distribution<>>(0, size(this->pimpl->p_cross) - 1);
	auto ret=this->pimpl->p_cross[index]->Cross(father, mother);

	return ret;
}

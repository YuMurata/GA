// GA.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include"GA.h"


using namespace std;



int main()
{
const string tar("HelloWorld");

	const int population = 10;
	const int genome_size = sizeof(char)*_BITS_BYTE;
	const int genomes_size = genome_size*size(tar);
	
	EvalFunc func = [&tar](const Conv &conv)
	{
		vector<double> dis_vec(size(conv));

		auto func = [](const int &x, const int &y)
		{
			auto ret = 1. / (1 + abs(x - y));
			return ret;
		};

		transform(begin(conv), end(conv), begin(tar), begin(dis_vec), func);

		auto sum = accumulate(begin(dis_vec), end(dis_vec), 0.);

		return sum;
	};

	DispFunc disp = [](const Conv &conv)
	{
		auto func = [](const string &left,const int &x)
		{
			string ret{ (char)x };
			return left+ret;
		};
		auto ret=accumulate(begin(conv),end(conv),string(),func);
		
		return ret;
	};

	GA ga_obj(population, genome_size, genomes_size, func,disp);

	ga_obj.Evolve();

	cout << "tar:" << tar << endl;
	//out << "sim:" <<gene[0]<< endl;
	_getch();
    return 0;
}


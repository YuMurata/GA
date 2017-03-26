// GA.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include"GA.h"


using namespace std;

#define HELLO

int main()
{

	const int population = 40;

	
#ifdef HELLO

	const string tar("HelloWorld");
	const int genome_size = sizeof(char)*_BITS_BYTE;
	const int genomes_size = genome_size*size(tar);
	
	EvalFunc func = [&tar](const Conv &conv)
	{
		vector<double> dis_vec(size(conv));

		auto func = [](const int &x, const int &y)
		{
			auto ret = 1. / (0.01 + abs(x - y));
			
			return ret;
		};

		transform(begin(conv), end(conv), begin(tar), begin(dis_vec), func);

		auto sum = accumulate(begin(dis_vec), end(dis_vec), 0.);

		return sum;
	};

	DispFunc disp = [](const Conv &conv)
	{
		auto func = [](const string &left, const int &x)
		{
			string ret{(char)x };
			return left + ret;
		};
		auto ret = accumulate(begin(conv), end(conv), string(), func);

		return ret;
	};
#else

	const int genome_size = sizeof(int);
	const int genomes_size = genome_size * 1;

	EvalFunc func = [](const Conv &conv)
	{
		vector<double> dis_vec(size(conv));

		auto func = [](const int &x)
		{
			auto ret = x;
			return ret;
		};

		transform(begin(conv), end(conv),begin(dis_vec), func);

		auto sum = accumulate(begin(dis_vec), end(dis_vec), 0.);

		return sum;
	};

	DispFunc disp = [](const Conv &conv)
	{
		auto func = [](const string &left,const int &x)
		{
			string ret{ to_string(x) };
			return left+ret;
		};
		auto ret=accumulate(begin(conv),end(conv),string(),func);
		
		return ret;
	};
#endif

	GA ga_obj(population, genome_size, genomes_size, func,disp);

	ga_obj.Evolve(1000,false);

	cout << "tar:" << tar << endl;
	//out << "sim:" <<gene[0]<< endl;
	_getch();
    return 0;
}


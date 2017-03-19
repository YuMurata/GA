#pragma once

using Genome = std::vector<int>;
using Conv = std::vector<int>;
using EvalFunc = std::function<double(const Conv &)>;
using DispFunc = std::function<std::string(const Conv &)>;
using GenomeList = std::vector<Genome>;
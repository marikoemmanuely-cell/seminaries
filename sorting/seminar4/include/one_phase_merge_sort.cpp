#include "one_phase_merge_sort.h"

#include <fstream>
#include <cstdio>
#include <utility>

template<typename T>
void onePhaseMergeSort(std::vector<T>& arr, const std::string& fileName)
{
	const size_t n = arr.size();
	if (n < 2) return;

	const std::string f[4] = { fileName + ".f1", fileName + ".f2",
							   fileName + ".f3", fileName + ".f4" };

	{   // distribution initiale : séries de longueur 1, alternées dans f1 et f2
		std::ofstream a(f[0]), b(f[1]);
		for (size_t i = 0; i < n; ++i)
			(i % 2 == 0 ? a : b) << arr[i] << ' ';
	}

	int in1 = 0, in2 = 1, out1 = 2, out2 = 3;

	for (size_t run = 1; run < n; run *= 2)
	{
		{
			std::ifstream a(f[in1]), b(f[in2]);
			std::ofstream c(f[out1]), d(f[out2]);
			T x{}, y{};
			bool hasX = static_cast<bool>(a >> x);
			bool hasY = static_cast<bool>(b >> y);
			bool toFirst = true;

			while (hasX || hasY)
			{
				std::ofstream& out = toFirst ? c : d;
				size_t i = 0, j = 0;

				while (i < run && j < run && hasX && hasY)
				{
					if (x <= y) { out << x << ' '; ++i; hasX = static_cast<bool>(a >> x); }
					else { out << y << ' '; ++j; hasY = static_cast<bool>(b >> y); }
				}
				while (i < run && hasX) { out << x << ' '; ++i; hasX = static_cast<bool>(a >> x); }
				while (j < run && hasY) { out << y << ' '; ++j; hasY = static_cast<bool>(b >> y); }

				toFirst = !toFirst;   // la série fusionnée suivante va dans l'autre fichier
			}
		}
		std::swap(in1, out1);   // les sorties deviennent les entrées
		std::swap(in2, out2);
	}

	arr.clear();
	{
		std::ifstream in(f[in1]);   // résultat final
		T v{};
		while (in >> v) arr.push_back(v);
	}

	for (const auto& name : f) std::remove(name.c_str());
}

template void onePhaseMergeSort<int>(std::vector<int>&, const std::string&);
template void onePhaseMergeSort<double>(std::vector<double>&, const std::string&);
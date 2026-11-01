#include "natural_merge_sort.h"

#include <fstream>
#include <cstdio>

template<typename T>
void naturalMergeSort(std::vector<T>& arr, const std::string& fileName)
{
	const std::string fileB = fileName + ".b";
	const std::string fileC = fileName + ".c";

	{   // tableau -> fichier principal
		std::ofstream out(fileName);
		for (const auto& x : arr) out << x << ' ';
	}

	while (true)
	{
		size_t runs = 0;

		{   // répartition : on change de fichier à chaque fin de série croissante
			std::ifstream in(fileName);
			std::ofstream b(fileB), c(fileC);
			T prev{}, cur{};
			bool toB = true, first = true;

			while (in >> cur)
			{
				if (first) { first = false; runs = 1; }
				else if (cur < prev) { toB = !toB; ++runs; }
				(toB ? b : c) << cur << ' ';
				prev = cur;
			}
		}

		if (runs <= 1) break;   // une seule série : le fichier est trié

		{   // fusion série par série
			std::ifstream b(fileB), c(fileC);
			std::ofstream out(fileName);
			T x{}, y{};
			bool hasX = static_cast<bool>(b >> x);
			bool hasY = static_cast<bool>(c >> y);

			while (hasX || hasY)
			{
				bool endX = !hasX, endY = !hasY;   // fin de la série courante

				while (!endX && !endY)
				{
					if (x <= y)
					{
						out << x << ' '; T p = x;
						hasX = static_cast<bool>(b >> x);
						if (!hasX || x < p) endX = true;
					}
					else
					{
						out << y << ' '; T p = y;
						hasY = static_cast<bool>(c >> y);
						if (!hasY || y < p) endY = true;
					}
				}
				while (!endX)
				{
					out << x << ' '; T p = x;
					hasX = static_cast<bool>(b >> x);
					if (!hasX || x < p) endX = true;
				}
				while (!endY)
				{
					out << y << ' '; T p = y;
					hasY = static_cast<bool>(c >> y);
					if (!hasY || y < p) endY = true;
				}
			}
		}
	}

	arr.clear();
	{
		std::ifstream in(fileName);
		T v{};
		while (in >> v) arr.push_back(v);
	}

	std::remove(fileB.c_str());
	std::remove(fileC.c_str());
}

template void naturalMergeSort<int>(std::vector<int>&, const std::string&);
template void naturalMergeSort<double>(std::vector<double>&, const std::string&);
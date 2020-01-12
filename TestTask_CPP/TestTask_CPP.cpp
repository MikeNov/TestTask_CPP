#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Path
{
public:
	string From;
	string To;
};

int main()
{
	int num;
#ifdef _DEBUG
	num = 3;
#else
	cout << "enter the number of city pairs:" << endl;
	cin >> num;
#endif

	vector<Path> vPaths;
	string fromOrTo;
	int i = 0;

	for (i = 0; i < num; i++)
	{
		Path ph;
		bool switcher = false;

#ifdef _DEBUG
		switch (i)
		{
		case 0:
			fromOrTo = "Moscow,Tumen";
			break;
		case 1:
			fromOrTo = "Tumen,Sochi";
			break;
		case 2:
			fromOrTo = "RostovNaDonu,Moscow";
			break;
		default:
			break;
		}
#else
		char outInfo[128];
		snprintf(outInfo, sizeof(outInfo), "%s{%d}%s{%d}", "enter the city pair <from-to>(from: City", 1 + i, ", to: city", 2 + i);
		cout << outInfo << endl;
	    cin >> fromOrTo;

		//getline(std::cin, fromOrTo);

#endif

		for (int j = 0; j < (int)fromOrTo.length(); j++)
		{
			if (!switcher && (fromOrTo[j] != ',' && fromOrTo[j] != ' '))
			{
				ph.From += fromOrTo[j];
			}
			else
			{
				if (!switcher)
					switcher = true;
			}
			if (switcher && (fromOrTo[j] != ',' && fromOrTo[j] != ' '))
				ph.To += fromOrTo[j];
		}
		vPaths.push_back(ph);
	}

	string resOutput;
	bool replaceFirstToLast = false;

	for (i = 0; i < (int)vPaths.size(); i++)
	{
		for (int ft = 0; ft < 2; ft++)
		{
			if (ft == 0)
				fromOrTo = vPaths[i].From;
			else
				fromOrTo = vPaths[i].To;

			if (i == 0 && fromOrTo == vPaths[(int)vPaths.size() - 1].To)
			{
				replaceFirstToLast = true;
				continue;
			}
			else if (i != 0 && fromOrTo == vPaths[i - 1].To)
				continue;

			resOutput += fromOrTo + (i == (int)vPaths.size() - 1 && ft != 0 ? "" : " ");
		}
	}
	
	if (replaceFirstToLast)
	{
		resOutput = resOutput.substr(resOutput.find_last_of(vPaths[(int)vPaths.size() - 1].From[0]))
			+ " "
			+ resOutput.substr(0, resOutput.length() - (vPaths[(int)vPaths.size() - 1].From.length() + vPaths[(int)vPaths.size() - 1].To.length() + 2));
	}
	cout << endl;
	cout << resOutput << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

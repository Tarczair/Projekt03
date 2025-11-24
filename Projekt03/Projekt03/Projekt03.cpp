#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sortuj {
public:
	void quick_sort(vector<T>& tab, int lewy, int prawy)
	{
		if (lewy >= prawy || tab.size() == 1) return;

		int i = lewy;
		int j = prawy;
		T pivot = tab[(lewy + prawy) / 2];

		while (i <= j)
		{
			while (tab[i] < pivot) i++;
			while (tab[j] > pivot) j--;

			if (i <= j)
			{
				swap(tab[i], tab[j]);
				i++;
				j--;
			}
		}

		if (lewy < j)
			quick_sort(tab, lewy, j);

		if (i < prawy)
			quick_sort(tab, i, prawy);
	}
};


int main()
{
	vector<int> tab1 = { 4, -7, 1, 2, 4 };
	Sortuj<int> s1;

	vector<double> tab2 = { -5.1341, -4.5512, -4.512, -4.5, -4.7 };
	Sortuj<double> s2;

	vector<float> tab3 = { -5.1341, -4.5512, -4.512, -4.5, -4.7 };
	Sortuj<float> s3;

	s1.quick_sort(tab1, 0, tab1.size() - 1);
	s2.quick_sort(tab2, 0, tab2.size() - 1);
	s3.quick_sort(tab3, 0, tab3.size() - 1);

	//wypisanie posortowanych elementów
	for (int x : tab1)
	{
		cout << x << " ";
	}

	cout << endl;
	for (double x : tab2)
	{
		cout << x << " ";
	}

	cout << endl;
	for (double x : tab3)
	{
		cout << x << " ";
	}
	return 0;
}
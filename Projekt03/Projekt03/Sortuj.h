#pragma once
#include <vector>

using namespace std;

template <typename T>
class Sortuj {
public:
    void merge_sort(vector<T>& tab, int lewy, int prawy)
    {
        if (lewy >= prawy) return;

        int srodek = (lewy + prawy) / 2;

        merge_sort(tab, lewy, srodek);
        merge_sort(tab, srodek + 1, prawy);

        merge(tab, lewy, srodek, prawy);
    }

private:
    void merge(vector<T>& tab, int lewy, int srodek, int prawy)
    {
        vector<T> temp;
        temp.reserve(prawy - lewy + 1);

        int i = lewy;
        int j = srodek + 1;

        while (i <= srodek && j <= prawy)
        {
            if (tab[i] <= tab[j])
                temp.push_back(tab[i++]);
            else
                temp.push_back(tab[j++]);
        }

        while (i <= srodek) temp.push_back(tab[i++]);
        while (j <= prawy) temp.push_back(tab[j++]);

        for (int k = 0; k < temp.size(); k++)
            tab[lewy + k] = temp[k];
    }
};

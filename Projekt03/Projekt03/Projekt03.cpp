#include <iostream>
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

        while (i <= srodek)
            temp.push_back(tab[i++]);

        while (j <= prawy)
            temp.push_back(tab[j++]);

        for (int k = 0; k < temp.size(); k++)
            tab[lewy + k] = temp[k];
    }
};


int main()
{
    vector<int> tab1 = { 4, -7, 1, 2, 4 };
    Sortuj<int> s1;

    vector<double> tab2 = { -5.1341, -4.5512, -4.512, -4.5, -4.7 };
    Sortuj<double> s2;

    vector<float> tab3 = { -5.1341f, -4.5512f, -4.512f, -4.5f, -4.7f };
    Sortuj<float> s3;

    s1.merge_sort(tab1, 0, tab1.size() - 1);
    s2.merge_sort(tab2, 0, tab2.size() - 1);
    s3.merge_sort(tab3, 0, tab3.size() - 1);

    // wypisanie wyników
    for (int x : tab1) cout << x << " ";
    cout << endl;

    for (double x : tab2) cout << x << " ";
    cout << endl;

    for (float x : tab3) cout << x << " ";

    return 0;
}


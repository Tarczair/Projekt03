/**
 * @file Sortuj.h
 * @brief Implementacja algorytmu sortowania za pomoc¹ sortowania scalaj¹cego (merge sort).
 *
 * Plik zawiera definicjê szablonowej klasy `Sortuj`, która implementuje algorytm sortowania
 * merge sort. Klasa ta operuje na dynamicznych tablicach typu `std::vector` i pozwala na
 * sortowanie elementów typu `T`. Implementacja jest w pe³ni ogólna, co pozwala na u¿ycie
 * klasy z dowolnym typem danych, który wspiera porównywanie (operator `<=`).
 */

#pragma once
#include <vector>

using namespace std;

/**
 * @class Sortuj
 * @brief Szablonowa klasa implementuj¹ca algorytm sortowania merge sort.
 *
 * Klasa `Sortuj` zawiera metody umo¿liwiaj¹ce posortowanie wektora danych za pomoc¹
 * algorytmu sortowania scalaj¹cego (merge sort). Jest to podejœcie dziel i zwyciê¿aj,
 * które dzieli tablicê na pó³, rekurencyjnie sortuje obie po³ówki, a nastêpnie scala je
 * w posortowan¹ tablicê.
 *
 * @tparam T Typ elementów w tablicy, musi wspieraæ porównania (operator `<=`).
 */
template <typename T>
class Sortuj {
public:
    /**
     * @brief Sortowanie tablicy za pomoc¹ algorytmu merge sort.
     *
     * Funkcja sortuje podany wektor `tab` w zakresie od indeksu `lewy` do `prawy`.
     * Algorytm dzia³a rekurencyjnie, dziel¹c tablicê na dwie czêœci, sortuj¹c je, a
     * nastêpnie scalaj¹c w jedn¹ posortowan¹ tablicê.
     *
     * @param tab Wektor, który ma zostaæ posortowany.
     * @param lewy Indeks pocz¹tkowy (w³¹cznie).
     * @param prawy Indeks koñcowy (w³¹cznie).
     */
    void merge_sort(vector<T>& tab, int lewy, int prawy)
    {
        if (lewy >= prawy) return;

        int srodek = (lewy + prawy) / 2;

        merge_sort(tab, lewy, srodek);
        merge_sort(tab, srodek + 1, prawy);

        merge(tab, lewy, srodek, prawy);
    }

private:
    /**
     * @brief Scala dwie czêœci tablicy w jedn¹ posortowan¹ tablicê.
     *
     * Funkcja ta ³¹czy dwie posortowane czêœci tablicy `tab` w jedn¹ posortowan¹ czêœæ.
     * Wektor `temp` jest u¿ywany do przechowywania poœrednich wyników scalania, a wynik
     * scalania jest kopiowany z powrotem do oryginalnej tablicy.
     *
     * @param tab Wektor, który ma zostaæ scalony.
     * @param lewy Indeks pocz¹tkowy lewej czêœci.
     * @param srodek Indeks œrodkowy (granica miêdzy obiema czêœciami).
     * @param prawy Indeks koñcowy prawej czêœci.
     */
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

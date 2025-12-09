/**
 * @file test.cpp
 * @brief Testy jednostkowe dla klasy Sortuj (merge sort).
 *
 * Plik zawiera zestaw testów jednostkowych dla klasy `Sortuj`, która implementuje algorytm sortowania
 * merge sort. Testy sprawdzaj¹ poprawnoœæ dzia³ania algorytmu w ró¿nych przypadkach, takich jak:
 * - Tablica ju¿ posortowana
 * - Tablica w odwrotnej kolejnoœci
 * - Tablica z losowymi wartoœciami
 * - Tablica zawieraj¹ca tylko liczby ujemne, tylko dodatnie oraz mieszane
 * - Tablica pusta, jednoelementowa i dwu-elementowa
 * - Tablica z powtarzaj¹cymi siê elementami
 * - Tablica o du¿ych rozmiarach
 *
 * Testy jednostkowe wykorzystuj¹ framework Google Test (gtest).
 */


#include "pch.h"
#include "gtest/gtest.h"
#include "../../Projekt03/Sortuj.h"

 /**
  * @test
  * Testuje algorytm merge sort dla tablicy ju¿ posortowanej.
  */
TEST(MergeSortTest, PosortowanaTablica) {
	vector<int> tab = { 1, 2, 3, 4, 5 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{1, 2, 3, 4, 5}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy w odwrotnej kolejnoœci.
 */
TEST(MergeSortTest, TablicaOdwrotnaKolejnosc) {
	vector<int> tab = { 5, 4, 3, 2, 1 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{1, 2, 3, 4, 5}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z losowymi liczbami.
 * Test jest powtarzalny dziêki ustalonemu ziarna (seed) dla funkcji rand().
 */
TEST(MergeSortTest, LosowaTablica) {
	srand(123);  // sta³y seed -> test powtarzalny

	vector<int> tab;
	const int size = 50;

	for (int i = 0; i < size; ++i) {
		tab.push_back(rand() % 200 - 100); // losowe liczby z zakresu [-100, 100]
	}

	// przygotuj osobn¹ poprawn¹ wersjê posortowan¹
	vector<int> expected = tab;
	sort(expected.begin(), expected.end());

	Sortuj<int> s;
	if (!tab.empty()) {
		s.merge_sort(tab, 0, tab.size() - 1);
	}

	EXPECT_EQ(tab, expected);
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy zawieraj¹cej tylko liczby ujemne.
 */
TEST(MergeSortTest, TylkoUjemneTablica) {
	vector<int> tab = { -5, -2, -9, -1 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{-9, -5, -2, -1}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy zawieraj¹cej liczby dodatnie i ujemne.
 */
TEST(MergeSortTest, UjemneIDodatnieTablica) {
	vector<int> tab = { 3, -2, 7, -1, 0 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{-2, -1, 0, 3, 7}));
}

/**
 * @test
 * Testuje algorytm merge sort dla pustej tablicy.
 * Sprawdza, czy algorytm nie rzuca wyj¹tku i tablica pozostaje pusta.
 */
TEST(MergeSortTest, PustaTablica) {
	vector<int> tab;
	Sortuj<int> s;
	EXPECT_NO_THROW(s.merge_sort(tab, 0, -1));
	EXPECT_TRUE(tab.empty());
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z jednym elementem.
 * Sprawdza, czy algorytm pozostawia tablicê bez zmian.
 */
TEST(MergeSortTest, TablicaJednoElementowa) {
	vector<int> tab = { 42 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{42}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z powtarzaj¹cymi siê liczbami dodatnimi.
 */
TEST(MergeSortTest, PowtarzajaceSieLiczbyDodatnieTablica) {
	vector<int> tab = { 4, 2, 4, 3, 2 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{2, 2, 3, 4, 4}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z powtarzaj¹cymi siê liczbami ujemnymi.
 */
TEST(MergeSortTest, PowtarzajaceSieLiczbyUjemneTablica) {
	vector<int> tab = { -3, -1, -3, -2 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{-3, -3, -2, -1}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z powtarzaj¹cymi siê liczbami dodatnimi i ujemnymi.
 */
TEST(MergeSortTest, PowtarzajaceSieDodatnieIUjemneLiczbyTablica) {
	vector<int> tab = { 3, -1, 3, 0, -1 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{-1, -1, 0, 3, 3}));
}

/**
 * @test
 * Testuje algorytm merge sort dla tablicy z dwoma elementami.
 */
TEST(MergeSortTest, DwuElemntowaTablica) {
	vector<int> tab = { 5, 2 };
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);
	EXPECT_EQ(tab, (vector<int>{2, 5}));
}

/**
 * @test
 * Testuje algorytm merge sort dla du¿ej tablicy z elementami w odwrotnej kolejnoœci.
 */
TEST(MergeSortTest, DuzoElementowaTablica) {
	vector<int> tab;
	for (int i = 200; i >= 0; --i) tab.push_back(i);
	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);

	vector<int> expected;
	for (int i = 0; i <= 200; ++i) expected.push_back(i);

	EXPECT_EQ(tab, expected);
}

/**
 * @test
 * Testuje algorytm merge sort dla du¿ej tablicy z powtarzaj¹cymi siê elementami.
 */
TEST(MergeSortTest, DuzoElementowaTablicaZPowtorzeniami) {
	vector<int> tab;
	for (int i = 100; i >= -100; --i) {
		tab.push_back(i);
		if (i % 10 == 0) tab.push_back(i);
	}

	Sortuj<int> s;
	s.merge_sort(tab, 0, tab.size() - 1);

	vector<int> expected;
	for (int i = -100; i <= 100; ++i) {
		expected.push_back(i);
		if (i % 10 == 0) expected.push_back(i);
	}

	EXPECT_EQ(tab, expected);
}
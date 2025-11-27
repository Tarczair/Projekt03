#include "pch.h"
#include "../Projekt03/Sortuj.h"

TEST(MergeSortTest, PosortowanaTablica) {
    vector<int> tab = { 1, 2, 3, 4, 5 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, TablicaOdwrotnaKolejnosc) {
    vector<int> tab = { 5, 4, 3, 2, 1 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, LosowaTablica) {
    srand(123);  // sta³y seed -> test powtarzalny

    vector<int> tab;
    const int size = 50;

    for (int i = 0; i < size; ++i) {
        tab.push_back(rand() % 200 - 100);
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


TEST(MergeSortTest, TylkoUjemneTablica) {
    vector<int> tab = { -5, -2, -9, -1 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{-9, -5, -2, -1}));
}

TEST(MergeSortTest, UjemneIDodatnieTablica) {
    vector<int> tab = { 3, -2, 7, -1, 0 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{-2, -1, 0, 3, 7}));
}

TEST(MergeSortTest, PustaTablica) {
    vector<int> tab;
    Sortuj<int> s;
    EXPECT_NO_THROW(s.merge_sort(tab, 0, -1));
    EXPECT_TRUE(tab.empty());
}

TEST(MergeSortTest, TablicaJednoElementowa) {
    vector<int> tab = { 42 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{42}));
}

TEST(MergeSortTest, PowtarzajaceSieLiczbyDodatnieTablica) {
    vector<int> tab = { 4, 2, 4, 3, 2 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{2, 2, 3, 4, 4}));
}

TEST(MergeSortTest, PowtarzajaceSieLiczbyUjemneTablica) {
    vector<int> tab = { -3, -1, -3, -2 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{-3, -3, -2, -1}));
}

TEST(MergeSortTest, PowtarzajaceSieDodatnieIUjemneLiczbyTablica) {
    vector<int> tab = { 3, -1, 3, 0, -1 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{-1, -1, 0, 3, 3}));
}

TEST(MergeSortTest, DwuElemntowaTablica) {
    vector<int> tab = { 5, 2 };
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);
    EXPECT_EQ(tab, (vector<int>{2, 5}));
}

TEST(MergeSortTest, DuzoElementowaTablica) {
    vector<int> tab;
    for (int i = 200; i >= 0; --i) tab.push_back(i);
    Sortuj<int> s;
    s.merge_sort(tab, 0, tab.size() - 1);

    vector<int> expected;
    for (int i = 0; i <= 200; ++i) expected.push_back(i);

    EXPECT_EQ(tab, expected);
}

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

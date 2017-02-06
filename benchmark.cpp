#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "reflib/bcis.hpp"
using namespace std;
using namespace reflib;

int main() {
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand_dist(0, 1000);
    for (int i=0; i<10; ++i) {
        vector<int> v1;
        vector<int> v2;
        cout << i*50 << endl;
        for (int j=0; j<50*i; ++j) {
            v1.push_back(rand_dist(mt));
            v2.push_back(rand_dist(mt));
        }

        auto start = chrono::system_clock::now();
        sort(v1.begin(), v1.end());
        auto end = chrono::system_clock::now();

        auto diff = end - start;
        cout << chrono::duration_cast<chrono::nanoseconds>(diff).count()
            << endl;

        auto start2 = chrono::system_clock::now();
        bci_sort(v2);
        auto end2 = chrono::system_clock::now();

        auto diff2 = end2 - start2;
        cout << chrono::duration_cast<chrono::nanoseconds>(diff2).count()
            << endl;
    }
}

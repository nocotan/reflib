#include <iostream>
#include <vector>
#include "reflib/ealgorithm.hpp"
#include "reflib/bcis.hpp"
using namespace std;
using namespace reflib;

int main() {
    vector<int> v = {5, 6, 2, 3, 1, 8};
    //clip(v, 2, 4);
    bci_sort(v);
    for (int i : v) {
        cout << i << endl;
    }
    cout << endl;
}

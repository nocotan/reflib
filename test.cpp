#include <iostream>
#include <vector>
#include "reflib/ealgorithm.hpp"
using namespace std;
using namespace reflib;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    clip(v, 2, 4);
    for (int i : v) {
        cout << i << endl;
    }
    cout << endl;
}

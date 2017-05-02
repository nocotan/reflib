#ifndef REFLIB_BCIS
#define REFLIB_BCIS

#include <cmath>

namespace reflib {

    template<typename T>
    void swap_elem(T& t, long long i, long long j) {
        long long tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }

    template<typename T>
    long long is_equal(T& t, long long sl, long long sr) {
        for (long long k=sl+1; k<=sr-1; ++k) {
            if (t[k] != t[sl]) {
                swap_elem(t, k, sl);
                return k;
            }
        }
        return -1;
    }

    template<typename T>
    void insert_right(T& t, long long curr, long long sr, long long right) {
        long long j = sr;
        while (j <= right && curr > t[j]) {
            t[j-1] = t[j];
            j++;
        }
        t[j-1] = curr;
    }

    template<typename T>
    void insert_left(T& t, long long curr, long long sl, long long left) {
        long long j = sl;
        while (j >= left && curr < t[j]) {
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = curr;
    }


    template<typename T>
    void bci_sort(T& t) {
        long long sl = 0;
        long long sr = t.size() - 1;

        while (sl < sr) {
            swap_elem(t, sr, sl+(sr-sl)/2);
            if (t[sl] == t[sr])
                if (is_equal(t, sl, sr) == -1) return;

            if (t[sl] > t[sr]) swap_elem(t, sl, sr);
            long long i;
            if (sr - sl >= 100) {
                i = sl+1;
                for (; i<=std::pow((sr-sl),0.5); ++i) {
                    if (t[sr] < t[i]) swap_elem(t, sr, i);
                    else if (t[sl] > t[i]) swap_elem(t, sl, i);
                }
            }
            else i = sl + 1;

            long long lc = t[sl];
            long long rc = t[sr];
            while (i < sr) {
                long long int curr = t[i];
                if (curr >= rc) {
                    t[i] = t[sr - 1];
                    insert_right(t, curr, sr, t.size()-1);
                    sr--;
                }
                else if (curr <= lc) {
                    t[i] = t[sl+1];
                    insert_left(t, curr, sl, 0);
                    sl++;
                    i++;
                }
                else {
                    i++;
                }
            }
            sl++;
            sr--;
        }
    }
}


#endif

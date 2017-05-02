/**
 * @file ealgorithm.hpp
 * @brief Effective standard template library
 * @author nocotan (noconoco.lib@gmail.com)
 * @date 2017-01-24
 */
#ifndef REFLIB_EALGORITHM_HPP
#define REFLIB_EALGORITHM_HPP

#include <algorithm>

namespace reflib {
    template<typename C>
    void clip(C& c, long long int min_, long long int max_) {
        for (int i=0; i<c.size(); ++i) {
            if (c[i] > max_) c[i] = max_;
            else if (c[i] < min_) c[i] = min_;
        }
    }
}

#endif

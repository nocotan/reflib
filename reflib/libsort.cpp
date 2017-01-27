#include <iostream>
#include <cmath>

namespace reflib {

#define MAX 10000
#define MAX2 20000

#define NONE -1

    bool isempty(int e) {
        return e < 0;
    }

    void prepareLibrarySort(int epsilon, int n, int S[MAX2], int* sLen) {
        int i;
        *sLen = (1+epsilon)*n;
        for(i=0;i<*sLen;i++) S[i] = NONE;
    }

    int searchFree(int e, int sorted[MAX2], int last) {
        int first = 0;
        int middle;

        while(last>=0 && isempty(sorted[last])) last --;
        while(first<=last && isempty(sorted[first])) first ++;
        while(first<=last) {
            middle = (first+last)/2;
            if(isempty(sorted[middle])) {
                int tmp = middle + 1;
                while(tmp<last && isempty(sorted[tmp])) tmp ++;
                if(sorted[tmp]>e) {
                    tmp = middle - 1;
                    while(middle>first && isempty(sorted[middle])) middle --;
                    if(sorted[middle]<e)
                        return middle;
                    last = middle - 1;
                } else first = tmp + 1;
            } else if(sorted[middle]<e) {
                first = middle + 1;
            } else {
                last = middle - 1;
            }
        }
        if(last>=0 && isempty(sorted[last])) last --;
        return last;
    }

    void libSort(int A[MAX], int N, int S[MAX2], int EPSILON) {
        if(N==0) return;
        int j, k, step;
        int goal = 1;
        int pos = 1;

        S[0] = A[0];

        int sLen = std::max((1+EPSILON), goal + 1);

        while(pos<N) {
            for(j=0;j<goal;j++) {
                int insPos = searchFree(A[pos], S, sLen-1);

                insPos ++;
                if(!isempty(S[insPos])) {
                    int nextFree = insPos + 1;
                    while(!isempty(S[nextFree])) nextFree ++;
                    if(nextFree>=sLen) {
                        insPos --;
                        if(!isempty(S[insPos])) {
                            nextFree = insPos - 1;
                            while(!isempty(S[nextFree])) nextFree --;
                            while(nextFree<insPos) {
                                S[nextFree] = S[nextFree+1];
                                nextFree ++;
                            }
                        }
                    } else {
                        while(nextFree>insPos) {
                            S[nextFree] = S[nextFree-1];
                            nextFree --;
                        }
                    }
                } else if(insPos>=sLen) {
                    insPos --;
                    int nextFree = insPos - 1;
                    while(!isempty(S[nextFree])) nextFree --;
                    while(nextFree<insPos) {
                        S[nextFree] = S[nextFree+1];
                        nextFree ++;
                    }
                }

                S[insPos] = A[pos ++];

                if(pos>=N)
                    return;
            }

            for(j=sLen-1, k=std::min(goal*(2+2*EPSILON), (1+EPSILON)*N)-1,
                    step=(k+1)/(j+1);j>=0;j--, k-=step) {
                S[k] = S[j];
                S[j] = NONE;
            }

            sLen = std::min(goal*(2+2*EPSILON), N*(1+EPSILON));
            goal <<= 1;
        }
    }

    void librarySort(int A[MAX], int n) {
        int epsilon = 1;
        int S[MAX2];
        int sLen, i, j;

        prepareLibrarySort(epsilon, n, S, &sLen);
        libSort(A, n, S, epsilon);
        for(i=0, j=0;i<sLen && j<n;i++)
            if(!isempty(S[i])) A[j++] = S[i];
    }
}

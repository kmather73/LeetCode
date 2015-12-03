#define MIN(a,b)  (a) ^ (((b) ^ (a)) & -((b) < (a)))

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int* indexes = (int*) calloc(primesSize, sizeof(int));
    int* uglyNums = (int*) malloc(sizeof(int)*n);

    *uglyNums = 1;

    for(int i = 1; i < n; ++i){
        int min = 0x7FFFFFFF;

        for(int j = 0; j < primesSize; ++j)
            min = MIN(min, uglyNums[indexes[j]]*primes[j]);

        uglyNums[i] = min;
        for(int j = 0; j < primesSize; ++j)
            if(uglyNums[indexes[j]]*primes[j] == min)
                ++indexes[j];
    }
    return uglyNums[n-1];
}

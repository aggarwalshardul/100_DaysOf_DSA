#include <stdlib.h>

#define MOD 1000000007LL
#define INV2 500000004LL   // modular inverse of 2 under MOD

// Compare function to sort by y-coordinate
int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if(p1[1] < p2[1]) return -1;
    if(p1[1] > p2[1]) return 1;
    return 0;
}

long long comb2(long long n) {
    return (n * (n - 1) / 2) % MOD;
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    
    if(pointsSize < 4)
        return 0;
    
    // Sort by y
    qsort(points, pointsSize, sizeof(int*), cmp);
    
    long long totalPairs = 0;
    long long sumSquares = 0;
    
    int i = 0;
    
    while(i < pointsSize) {
        int j = i;
        
        // Count same y
        while(j < pointsSize && points[j][1] == points[i][1])
            j++;
        
        long long count = j - i;
        
        if(count >= 2) {
            long long pairs = comb2(count);
            totalPairs = (totalPairs + pairs) % MOD;
            sumSquares = (sumSquares + (pairs * pairs) % MOD) % MOD;
        }
        
        i = j;
    }
    
    long long ans = ( (totalPairs * totalPairs) % MOD - sumSquares + MOD ) % MOD;
    ans = (ans * INV2) % MOD;
    
    return (int)ans;
}
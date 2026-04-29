#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with minimum distance = dist
int canPlace(int position[], int n, int m, int dist) {
    int count = 1;  // first ball placed
    int last = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
        }
        if (count >= m) return 1; // true
    }
    return 0; // false
}

int maxDistance(int position[], int n, int m) {
    // Step 1: sort array
    qsort(position, n, sizeof(int), compare);

    int low = 1;
    int high = position[n - 1] - position[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(position, n, m, mid)) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger distance
        } else {
            high = mid - 1;   // try smaller distance
        }
    }

    return ans;
}
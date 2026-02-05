#include <stdio.h>

int main() {
    int p, q;
    
    // Read size of first log
    scanf("%d", &p);
    int a[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int b[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Merge both sorted logs
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    // Copy remaining elements
    while (i < p) {
        merged[k++] = a[i++];
    }
    while (j < q) {
        merged[k++] = b[j++];
    }

    // Output merged log
    for (int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}

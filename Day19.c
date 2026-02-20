#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Using a simple large array as hash map
    // Range assumption: prefix sums within [-100000, 100000]
    int hash[200001] = {0};

    // Shift index to handle negative sums
    int offset = 100000;

    hash[offset] = 1;  // prefixSum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}
#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;   // Handle k > n

    // Step 1: Reverse whole array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);

    reverse(arr, k, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

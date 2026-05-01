#include <stdio.h>

// Helper function to check if given capacity works
int canShip(int weights[], int n, int days, int capacity) {
    int requiredDays = 1;
    int currWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currWeight + weights[i] > capacity) {
            requiredDays++;
            currWeight = weights[i];
        } else {
            currWeight += weights[i];
        }
    }
    return requiredDays <= days;
}

// Main function
int shipWithinDays(int weights[], int n, int days) {
    int maxW = weights[0];
    int sum = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (weights[i] > maxW) maxW = weights[i];
        sum += weights[i];
    }

    int low = maxW;
    int high = sum;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, n, days, mid)) {
            high = mid;   // try smaller capacity
        } else {
            low = mid + 1; // increase capacity
        }
    }

    return low;
}
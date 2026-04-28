int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int low = 1, high = x;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Use division to avoid overflow
        if (mid <= x / mid) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;   // go smaller
        }
    }

    return ans;
}
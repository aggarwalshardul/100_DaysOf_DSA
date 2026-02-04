int missingNum(int *arr, int size) {

    int n = size + 1;
    int xr = 0;

    for (int i = 1; i <= n; i++)
        xr ^= i;

    for (int i = 0; i < size; i++)
        xr ^= arr[i];

    return xr;

}

#include <stdio.h>

int main() {
    int m, n;

    // Read dimensions
    scanf("%d %d", &m, &n);

    // Check if matrix is square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int matrix[m][n];

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");

    return 0;
}

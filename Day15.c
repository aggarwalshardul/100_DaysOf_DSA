#include <stdio.h>

int main() {
    int m, n;
    
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    // Calculate primary diagonal sum
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    
    printf("Sum of primary diagonal = %d", sum);
    
    return 0;
}

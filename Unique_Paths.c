

int uniquePaths(int m, int n){
    int matrix[m][n];
    int i, j;
    for ( i = 0; i < m; i++){
        matrix[i][0] = 1;
    }
    for ( j = 0; j < n; j++){
        matrix[0][j] = 1;
    }
    for (i = 1; i < m; i++){
        for (j = 1; j < n; j++){
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        }
    }
    return matrix[m-1][n-1];
}
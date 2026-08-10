#include <stdio.h>

void setZeroes(int rows, int cols, int matrix[rows][cols]) {
  int col = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        if (j == 0) {
          col = 0;
        } else {
          matrix[0][j] = 0;
        }
        matrix[i][0] = 0;
      }
    }
  }

  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      if (matrix[0][j] == 0 || matrix[i][0] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if (matrix[0][0] == 0) {
    for (int j = 0; j < cols; j++) {
      matrix[0][j] = 0;
    }
  }

  if (col == 0) {
    for (int i = 0; i < rows; i++) {
      matrix[i][0] = 0;
    }
  }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows, cols;

  scanf("%d", &rows);

  scanf("%d", &cols);

  int matrix[rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  setZeroes(rows, cols, matrix);

  printMatrix(rows, cols, matrix);

  return 0;
}

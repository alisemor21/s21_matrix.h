#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

int minor_m(int skip_row, int skip_column, matrix_t *M, matrix_t *result) {
  s21_create_matrix(M->rows - 1, M->columns - 1, result);

  int di = 0, dj = 0;

  for (int i = 0; i < result->rows; i++) {
    if (i == skip_row) {
      di = 1;
    }
    dj = 0;

    for (int j = 0; j < result->columns; j++) {
      if (j == skip_column) {
        dj = 1;
      }
      result->matrix[i][j] = M->matrix[i + di][j + dj];
    }
  }
  return 0;
}
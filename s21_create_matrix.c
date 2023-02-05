#include <stdlib.h>

#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (rows < 1 || columns < 1 || result == NULL) {
    res = BAD_MATRIX;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->columns = columns;
    result->rows = rows;
  }

  return res;
}

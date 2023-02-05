#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A != NULL && (A->columns > 0 && A->rows > 0)) {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }

  } else {
    res = 1;
  }

  return res;
}
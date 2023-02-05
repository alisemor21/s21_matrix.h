#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

double det(matrix_t *M) {
  double result = 0;

  if (M->rows == 1)
    result = M->matrix[0][0];
  else if (M->rows == 2)
    result = (M->matrix[0][0] * M->matrix[1][1]) -
             (M->matrix[0][1] * M->matrix[1][0]);
  else {
    int sign = 1;
    for (int i = 0; i < M->rows; i++) {
      matrix_t temp;
      minor_m(0, i, M, &temp);

      result += sign * M->matrix[0][i] * det(&temp);
      sign *= -1;

      s21_remove_matrix(&temp);
    }
  }

  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = 0;

  if (A == NULL)
    code = 1;
  else if (A->rows != A->columns)
    code = 2;
  else
    *result = det(A);

  return code;
}

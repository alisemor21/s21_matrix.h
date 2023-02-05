#include <stdlib.h>

#include "math.h"
#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (!s21_correct_matrix(A))
    code = BAD_MATRIX;
  else if (A->rows != A->columns)
    code = CALC_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);

    if (A->rows == 1)
      result->matrix[0][0] = A->matrix[0][0];
    else {
      int sign;
      matrix_t temp;

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor_m(i, j, A, &temp);
          sign = ((i + j) % 2 == 0) ? 1 : -1;
          result->matrix[i][j] = det(&temp) * sign;
          s21_remove_matrix(&temp);
        }
      }
    }
  }

  return code;
}

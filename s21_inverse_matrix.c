#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (!s21_correct_matrix(A))
    code = BAD_MATRIX;
  else if (A->rows != A->columns)
    code = CALC_ERROR;
  else {
    double determinant = det(A);

    if (fabs(determinant) < 1e-7)
      code = CALC_ERROR;
    else {
      matrix_t comp, trans;

      s21_calc_complements(A, &comp);
      s21_transpose(&comp, &trans);
      s21_mult_number(&trans, 1 / determinant, result);
      s21_remove_matrix(&comp);
      s21_remove_matrix(&trans);
    }
  }

  return code;
}
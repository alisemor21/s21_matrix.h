#include <math.h>

#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_correct_matrix(A) && s21_correct_matrix(B)) {
    if (s21_is_equal_size(A, B)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabsl(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
            return FAILURE;
          }
        }
      }
    } else {
      return FAILURE;
    }
  } else {
    return FAILURE;
  }
  return SUCCESS;
}

#include <stdlib.h>

#include "s21_matrix.h"

int s21_correct_matrix(matrix_t *A) {
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
    return 0;
  return 1;
}

int s21_is_equal_size(matrix_t *A, matrix_t *B) {
  if (A->rows == B->rows && A->columns == B->columns) {
    return 1;
  }
  return 0;
}
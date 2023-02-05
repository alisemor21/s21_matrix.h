#include "s21_matrix.h"
#include "tests/tests.h"

int main() {
  int no_failed = 0;
  no_failed += test_all();
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

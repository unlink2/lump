#include "parse.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

void test_trim(void **state) {
  char *c = "   test";
  int len = (int)strlen(c);
  const char *res = lump_trim(c, &len);
  assert_string_equal("test", res);
  assert_int_equal(4, len);
}

int main(int arc, char **argv) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_trim),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

#include "parse.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

void test_strisspace(void **state) {
  assert_true(lump_strisspace("    ", 99));
  assert_false(lump_strisspace("   test   ", 99));
}

void test_trim(void **state) {
  char *c = "   test";
  int len = (int)strlen(c);
  const char *res = lump_trim(c, &len);
  assert_string_equal("test", res);
  assert_int_equal(4, len);
}

void assert_tok(const char *tok, const char *expected, int expected_len) {
  int dst_len = 256;
  char dst[dst_len];
  int len = lump_tok(dst, tok, dst_len);
  assert_string_equal(expected, dst);
  assert_int_equal(expected_len, len);
}

void test_tok(void **state) {
  assert_tok("", "", 0);
  assert_tok("   ", "", 3);
  assert_tok("single", "single", 6);
  assert_tok("multi token", "multi", 5);
  assert_tok("new\nline", "new", 3);
  assert_tok(" \nline", "\n", 2);
  assert_tok("  spaces", "spaces", 8);
}

void assert_slice(const char *tok, const char *expected, int expected_len,
                  int from, int to) {
  int dst_len = 256;
  char dst[dst_len];
  int len = lump_slice(dst, tok, dst_len, from, to);
  assert_string_equal(expected, dst);
  assert_int_equal(expected_len, len);
}

void test_slice(void **state) {
  assert_slice("", "", 0, 0, 0);
  assert_slice("", "", -1, 1, 0);
  assert_slice("", "", -1, 257, 0);
  assert_slice("", "", -1, 0, 257);

  assert_slice("from start to end", "from start to end", 18, 0, 18);
  assert_slice("from start", "from st", 7, 0, 7);
  assert_slice("from middle", " middle", 7, 4, 11);
  assert_slice("from middle", " midd", 5, 4, 9);
}

int main(int arc, char **argv) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_trim), cmocka_unit_test(test_strisspace),
      cmocka_unit_test(test_tok), cmocka_unit_test(test_slice)};

  return cmocka_run_group_tests(tests, NULL, NULL);
}

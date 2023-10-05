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
  assert_tok("   ", "   ", 3);
  assert_tok("single", "single", 6);
  assert_tok("multi token", "multi token", 11);
  assert_tok("new\nline", "new\nline", 8);
  assert_tok(" \nline", " \n", 2);
  assert_tok("  spaces", "  spaces", 8);

  assert_tok("  #", "  ", 2);
  assert_tok("#", "#", 1);
  assert_tok("##", "###", 2);
  assert_tok("###", "###", 3);
  assert_tok("####", "####", 4);
  assert_tok("#####", "#####", 5);
  assert_tok("######", "######", 6);

  assert_tok("###### test", "######", 6);
  assert_tok("####### test", "####### test", 7);

  assert_tok("test #", "test #", 6);
}

int main(int arc, char **argv) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_trim),
      cmocka_unit_test(test_strisspace),
      cmocka_unit_test(test_tok),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

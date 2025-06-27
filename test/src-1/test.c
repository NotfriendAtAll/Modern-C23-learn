#include "test.h"

static void test_strlen(void **state) {
    (void)state;
    assert_int_equal(strlen("hello"), 5);
    assert_int_equal(strlen(""), 0);
}

static void test_memcpy(void **state) {
    (void)state;
    char src[] = "world";
    char dest[10] = {0};
    memcpy(dest, src, strlen(src) + 1);
    assert_string_equal(dest, "world");
}

static void test_memcmp(void **state) {
    (void)state;
    char a[] = "abc";
    char b[] = "abd";
    assert_true(memcmp(a, b, 3) < 0);
    assert_true(memcmp(a, a, 3) == 0);
}

static void test_memchr(void **state) {
    (void)state;
    char s[] = "hello";
    char *pch = memchr(s, 'l', strlen(s));
    assert_non_null(pch);
    assert_int_equal(pch - s, 2);
    assert_null(memchr(s, 'z', strlen(s)));
}

static void test_strcpy(void **state) {
    (void)state;
    char src[] = "hello";
    char dest[10];
    strcpy(dest, src);
    assert_string_equal(dest, "hello");
}

static void test_strcmp(void **state) {
    (void)state;
    assert_true(strcmp("abc", "abd") < 0);
    assert_true(strcmp("abc", "abc") == 0);
    assert_true(strcmp("abd", "abc") > 0);
}

static void test_strcoll(void **state) {
    (void)state;
    setlocale(LC_COLLATE, "");
    assert_true(strcoll("abc", "abd") < 0);
}

static void test_strchr(void **state) {
    (void)state;
    char s[] = "hello";
    char *pos = strchr(s, 'e');
    assert_non_null(pos);
    assert_int_equal(pos - s, 1);
    assert_null(strchr(s, 'z'));
}

static void test_strspn(void **state) {
    (void)state;
    assert_int_equal(strspn("abc123", "abc"), 3);
    assert_int_equal(strspn("123abc", "abc"), 0);
}

static void test_strdup(void **state) {
    (void)state;
    char *dup = strdup("hello");
    assert_non_null(dup);
    assert_string_equal(dup, "hello");
    free(dup);
}

static void test_strndup(void **state) {
    (void)state;
    char *ndup = strndup("abcdef", 3);
    assert_non_null(ndup);
    assert_memory_equal(ndup, "abc", 3);
    assert_int_equal(ndup[3], '\0');
    free(ndup);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_strlen),
        cmocka_unit_test(test_memcpy),
        cmocka_unit_test(test_memcmp),
        cmocka_unit_test(test_memchr),
        cmocka_unit_test(test_strcpy),
        cmocka_unit_test(test_strcmp),
        cmocka_unit_test(test_strcoll),
        cmocka_unit_test(test_strchr),
        cmocka_unit_test(test_strspn),
        cmocka_unit_test(test_strdup),
        cmocka_unit_test(test_strndup),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
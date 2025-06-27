#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <cmocka.h>


// 被测函数示例（可根据需要引入头文件或声明外部函数）
extern size_t strlen(const char *s);
extern void *memcpy(void *dest, const void *src, size_t n);
extern int memcmp(const void *s1, const void *s2, size_t n);
extern void *memchr(const void *s, int c, size_t n);
extern char *strcpy(char *dest, const char *src);
extern int strcmp(const char *s1, const char *s2);
extern int strcoll(const char *s1, const char *s2);
extern char *strchr(const char *s, int c);
extern size_t strspn(const char *s, const char *accept);
extern char *strdup(const char *s);
extern char *strndup(const char *s, size_t n);

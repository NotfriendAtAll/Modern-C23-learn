#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // strlen 示例
    char s[] = "hello";
    printf("字符串: %s\n", s);
    printf("strlen(s): %zu\n", strlen(s)); // 5

    // memcpy 示例
    char src[] = "world";
    char dest[10];
    memcpy(dest, src, strlen(src) + 1); // 包含 '\0'
    printf("memcpy 结果: %s\n", dest);

    // memcmp 示例
    char a[] = "abc";
    char b[] = "abd";
    int cmp = memcmp(a, b, 3);
    printf("memcmp(a, b, 3): %d\n", cmp); // <0

    // memchr 示例
    char *pch = memchr(s, 'l', strlen(s));
    if (pch)
        printf("memchr: 'l' 在 \"%s\" 的第 %ld 个位置\n", s, pch - s);

    // strcpy 示例（不安全，仅演示）
    char copy[10];
    strcpy(copy, s);
    printf("strcpy 结果: %s\n", copy);

    // strcmp 示例
    printf("strcmp(\"abc\", \"abd\"): %d\n", strcmp("abc", "abd")); // <0

    // strcoll 示例（本地化比较）
    setlocale(LC_COLLATE, "");
    printf("strcoll(\"abc\", \"abd\"): %d\n", strcoll("abc", "abd"));

    // strchr 示例
    char *pos = strchr(s, 'e');
    if (pos)
        printf("strchr: 'e' 在 \"%s\" 的第 %ld 个位置\n", s, pos - s);

    // strspn 示例
    printf("strspn(\"abc123\", \"abc\"): %zu\n", strspn("abc123", "abc")); // 3

    // strdup 示例（C23 新增，部分编译器已支持）
    char *dup = strdup(s);
    printf("strdup 结果: %s\n", dup);
    free(dup);

    // strndup 示例
    char *ndup = strndup("abcdef", 3);
    printf("strndup 结果: %s\n", ndup);
    free(ndup);

    return 0;
}

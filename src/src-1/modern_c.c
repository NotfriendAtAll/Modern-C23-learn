#define __STDC_WANT_LIB_EXT1__ 1
#include <safe_lib.h>
#include <safe_mem_lib.h>
#include <safe_str_lib.h>
#include <stdalign.h>
#include <stdbit.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// 测试安全字符串复制与边界检查
void test_strcpy_safe()
{
  char dest[20];
  const char* src = "SafeC test";

  // 安全复制：检查目标缓冲区大小
  errno_t err = strcpy_s(dest, sizeof(dest), src);
  if (err != 0) {
    printf("strcpy_s failed! Error: %d\n", err);
  }
  else {
    printf("Copied: %s\n", dest);
  }

  // 测试溢出场景
  const char* long_src = "This string is too long for the destination buffer";
  err = strcpy_s(dest, sizeof(dest), long_src);
  if (err == ERANGE) {  // 溢出错误码
    printf("Expected overflow blocked: %s\n", strerror(err));
  }
}

// 测试安全内存复制与清零
void test_memcpy_and_clear()
{
  int src[5] = {1, 2, 3, 4, 5};
  int dest[5];

  // 安全内存复制
  errno_t err = memcpy_s(dest, sizeof(dest), src, sizeof(src));
  if (err != 0) {
    printf("memcpy_s error: %d\n", err);
    return;
  }

  // 验证复制结果
  for (int i = 0; i < 5; i++) {
    printf("dest[%d] = %d\n", i, dest[i]);
  }

  // 安全清零内存
  memset_s(dest, sizeof(dest), 0, sizeof(dest));
  printf("Memory cleared.\n");
}

// 测试安全字符串连接
void test_strcat_safe()
{
  char dest[30] = "Hello, ";
  const char* name = "SafeC User!";

  // 安全连接：自动计算剩余空间
  errno_t err = strcat_s(dest, sizeof(dest), name);
  if (err != 0) {
    printf("strcat_s error: %d\n", err);
  }
  else {
    printf("Concatenated: %s\n", dest);
  }
}

// 测试安全格式化输出
void test_sprintf_safe()
{
  char buffer[50];
  int id = 100;

  // 安全格式化：避免缓冲区溢出
  errno_t err = sprintf_s(buffer, sizeof(buffer), "User ID: %d", id);
  if (err != 0) {
    printf("sprintf_s error: %d\n", err);
  }
  else {
    printf("Formatted: %s\n", buffer);
  }
}
struct ModernC
{
  int value;
  char array[10];
  char index;
};

int main()
{
  size_t res = 10;
  printf("%u ", stdc_bit_width(res));
  printf("%u ", stdc_has_single_bit(res));
  printf("%u ", stdc_count_ones(res));
  printf("%zu ", stdc_bit_floor(res));
  printf("%zu ", offsetof(struct ModernC, value));
  printf("%zu ", offsetof(struct ModernC, array));
  printf("%zu ", alignof(struct ModernC));
  printf("-----------------\n");
  int value = 123;

  printf("%d\t", value);    // 123 (默认)
  printf("%8d\t", value);   //      123 (右对齐，宽度8)
  printf("%-8d\t", value);  // 123      (左对齐，宽度8)
  printf("%08d\t", value);  // 00000123 (零填充，宽度8)
  printf("%+d\t", value);   // +123 (强制显示正号)
  printf("--------------------\n");
  auto file = fopen("output.txt", "w");
  if (file != nullptr) {
    fprintf(file, "写入文件: %d\n", 42);
    fprintf(stderr, "错误信息: %s\n", "测试错误");
    fclose(file);
  }
  printf("------------------\n");
  int num = 42;
  float pi = 3.14159;
  auto name = "Alice";

  printf("整数: %d\t", num);        // 整数: 42
  printf("浮点数: %.2f\t", pi);     // 浮点数: 3.14
  printf("字符串: %s\t", name);     // 字符串: Alice
  printf("十六进制: 0x%x\t", num);  // 十六进制: 0x2a
  printf("-------------------\n");
  printf("===== Safec Library Test =====\n");
  test_strcpy_safe();
  test_memcpy_and_clear();
  test_strcat_safe();
  test_sprintf_safe();
  printf("===== Tests Completed =====\n");

  return 0;
}
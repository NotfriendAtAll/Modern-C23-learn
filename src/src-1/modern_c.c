#include <stdalign.h>
#include <stdbit.h>
#include <stddef.h>
#include <stdio.h>

struct ModernC
{
  int value;
  char array[10];
  char index;
};

int main()
{
  size_t res = 10;
  printf("%u\n", stdc_bit_width(res));
  printf("%u\n", stdc_has_single_bit(res));
  printf("%u\n", stdc_count_ones(res));
  printf("%zu\n", stdc_bit_floor(res));
  printf("%zu\n", offsetof(struct ModernC, value));
  printf("%zu\n", offsetof(struct ModernC, array));
  printf("%zu\n", alignof(struct ModernC));
  printf("-----------------\n");
  int value = 123;

  printf("%d\n", value);    // 123 (默认)
  printf("%8d\n", value);   //      123 (右对齐，宽度8)
  printf("%-8d\n", value);  // 123      (左对齐，宽度8)
  printf("%08d\n", value);  // 00000123 (零填充，宽度8)
  printf("%+d\n", value);   // +123 (强制显示正号)
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
  auto  name = "Alice";

  printf("整数: %d\n", num);        // 整数: 42
  printf("浮点数: %.2f\n", pi);     // 浮点数: 3.14
  printf("字符串: %s\n", name);     // 字符串: Alice
  printf("十六进制: 0x%x\n", num);  // 十六进制: 0x2a
  return 0;
}
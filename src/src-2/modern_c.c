
#include <stdint.h>
#if !__has_include(<stdio.h>)
# error "this file needs the <stdio.h> header"
#endif
#include <stdio.h>
#include <limits.h>


void do_something(void);
int main(void) {
    // 无符号循环：行为可预测
for (unsigned i = 1; i; ++i) do_something();  // 遍历所有值后停止

// 有符号循环：隐含未定义行为(UB)
for (signed i = 1; i; ++i) do_something();    // 溢出时行为未定义
auto res=INT_MIN < -INT_MAX;
    printf("Hello, Modern C!\n");
    printf("res:%d\n",res);
double E[] = { [3] = 42.0, [2] = 37.0 }; // 类型为 double[4]
double F[] = { 22.0, 17.0, 1, 0.5 };     // 类型为 double[4]
printf("%zu ",sizeof(E) / sizeof(E[0])); // 输出 4
printf("%zu ",sizeof(F)); // 输出 8,退化成指针
  return 0;
}
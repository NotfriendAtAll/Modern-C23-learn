#include <stdio.h>
#include <string.h>
#include <wchar.h>

struct birdStruct
{
  char const* jay;
  char const* magpie;
  char const* raven;
  char const* chough;
};
struct birdStruct const aName = {
    .chough = "Henry",
    .raven = "Lissy",
    .magpie = "Frau",
    .jay = "Joe",
};
// 未优化：12字节
struct Unoptimized
{
  char a;
  int b;
  char c;
};

// 优化后：8字节
struct Optimized
{
  int b;
  char a;
  char c;
};
#pragma pack(1)  // 1字节对齐
struct Packed
{
  char a;
  int b;
};  // 大小=5字节
struct tib {
    unsigned int tib_sec :6;  // 错误：int位域可能导致符号问题,变成负数
    // 应改为 unsigned int
};
int main(int argc, char* argv[])
{
  char* name = nullptr;  // nullptr是C++中的关键字，C23标准新增
  char* greeting = "";   // 访问空字符串是未定义行为
  printf("Hello %s, %s, %s, %s\n", aName.jay, aName.magpie, aName.raven,
         aName.chough);
  printf("Unoptimized struct size: %zu bytes\n", sizeof(struct Unoptimized));
  printf("Optimized struct size: %zu bytes\n", sizeof(struct Optimized));
  printf("Packed struct size: %zu bytes\n", sizeof(struct Packed));
  printf("Aligned struct size: %zu bytes\n", sizeof(struct tib));
  // 12位无符号常量（适配不同平台）
const unsigned _BitInt(12) MAX_VALUE = 0xFFFuwb; // 4095,BitInt(N)类型表示宽度为  N  的数值位域

// 编译器自动处理位宽
auto result = MAX_VALUE + 1; // 结果 0（模 4096）

// 类型安全的表达式
static_assert(sizeof(MAX_VALUE) == 2, "12位占用2字节"); //c11引入
for (int i=0; i<argc; ++i) {
  printf("Argument %d: %s\n", i, argv[i]);
}
char u8str[] = u8"Hello, 世界"; // C23新增的UTF-8字符串字面量
printf("UTF-8 string: %s\n", u8str);
auto α = 1;
auto β = 2.5; // C23新增的自动类型推断
printf("Auto type α: %d, β: %.2f\n", α, β);
auto \u01F4A9 = "💩"; // C23新增的Unicode字符字面量
printf("Unicode character: %s\n", \u01F4A9);
/*Unicode 字符的编码长度需运行时确定​
Unicode 字符的字节长度取决于编码方式（如 UTF-8 或 UTF-16）：

​UTF-8​：💩（U+1F4A9）占 ​4 字节​（编码为 F0 9F 92 A9）。
​UTF-16​：占 ​4 字节​（代理对 D83D DCA9）。
sizeof 在编译时无法获取这种动态信息
*/
// 方法1：UTF-8 编码
char utf8_str[] = u8"\U0001F4A9";  // 使用 U+ 格式
printf("UTF-8 字节长度: %zu\n", strlen(utf8_str));  // 输出 4

// 方法2：宽字符（如 UTF-16）
wchar_t wstr[] = L"\U0001F4A9";
printf("UTF-16 字节长度: %zu\n", wcslen(wstr) * sizeof(wchar_t));  // 输出 4（假设 wchar_t 为 2 字节）
  return 0;
}
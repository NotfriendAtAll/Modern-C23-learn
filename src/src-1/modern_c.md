[TOC]
# C23 新特性 stdalign.h、stddef.h、stdbit.h 说明与实用示例

## 安装safec library
```bash
git clone https://github.com/rurban/safeclib.git  # 克隆源码
cd safeclib
./build-aux/autogen.sh  # 生成配置脚本
./configure             # 检查环境并生成Makefile
make                    # 编译源码
sudo make install       # 安装到系统目录（默认路径：/usr/local/lib）
```
## 安装CMocka
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install libcmocka-dev  # 安装开发库及头文件

# CentOS/RHEL
sudo yum install epel-release  # 启用 EPEL 仓库
sudo yum install cmocka-devel
```
本文以如下代码为例，详细讲解 C23 新增及增强的标准库函数/宏：  
- stdc_bit_width
- stdc_has_single_bit
- stdc_count_ones
- stdc_bit_floor
- offsetof
- alignof

并说明它们的头文件、参数类型、返回类型、功能及相关的类似函数。

---
## 提醒
```bash
以下函数的结果与参数的类型无关：  stdc_bit_floor,stdc_bit_width,stdc_count_ones,stdc_has_single_bit,  
stdc_first_trailing_one,stdc_first_trailing_zero
---
以下函数的结果取决于参数类型的宽度：
stdc_bit_ceil,stdc_count_zeros,stdc_first_leading_one
stdc_first_leading_zero,stdc_leading_ones
stdc_leading_zeros,stdc_trailing_ones,stdc_trailing_zeros
```
***
## 详细解释

### 1. `stdc_bit_width`

- **头文件**：`<stdbit.h>`
- **函数原型**：`unsigned stdc_bit_width(unsigned x);`（也接受其他无符号整数类型）
- **功能说明**：返回能表示 `x` 的最小二进制位数（不计符号位）。即 `x` 的二进制表示需要多少位。
- **参数类型**：整型（通常为无符号数）
- **返回值类型**：`unsigned`
- **示例**：`stdc_bit_width(10)` 返回 4，因为 10 的二进制是 `1010`，需要 4 位。
- **类似函数**：
  - `stdc_count_ones`：统计 1 的个数
  - `stdc_count_leading_zeros`
  - `stdc_count_trailing_zeros`

---

### 2. `stdc_has_single_bit`

- **头文件**：`<stdbit.h>`
- **函数原型**：`unsigned stdc_has_single_bit(unsigned x);`
- **功能说明**：判断 `x` 是否是 2 的幂（只有一个二进制位为 1），是则返回 1，否则返回 0。
- **参数类型**：整型
- **返回值类型**：`unsigned`
- **示例**：`stdc_has_single_bit(8)` 返回 1，`stdc_has_single_bit(10)` 返回 0
- **类似函数**：
  - `stdc_bit_ceil`：返回大于等于 x 的最小 2 的幂

---

### 3. `stdc_count_ones`

- **头文件**：`<stdbit.h>`
- **函数原型**：`unsigned stdc_count_ones(unsigned x);`
- **功能说明**：返回 `x` 的二进制中 1 的个数（即“汉明重量”）。
- **参数类型**：整型
- **返回值类型**：`unsigned`
- **示例**：`stdc_count_ones(10)` 返回 2，因为 10（二进制 1010）有 2 个 1。
- **类似函数**：
  - `stdc_count_leading_zeros`
  - `stdc_count_trailing_zeros`

---

### 4. `stdc_bit_floor`

- **头文件**：`<stdbit.h>`
- **函数原型**：`size_t stdc_bit_floor(size_t x);`
- **功能说明**：返回小于或等于 `x` 的最大 2 的幂。
- **参数类型**：整型
- **返回值类型**：与参数同类型
- **示例**：`stdc_bit_floor(10)` 返回 8
- **类似函数**：
  - `stdc_bit_ceil`：返回大于等于 x 的最小 2 的幂

---

### 5. `offsetof`

- **头文件**：`<stddef.h>`
- **宏定义**：`#define offsetof(type, member)`
- **功能说明**：返回结构体成员相对于结构体起始地址的字节偏移量。
- **参数类型**：
  - `type`：结构体类型
  - `member`：结构体成员名
- **返回值类型**：`size_t`
- **示例**：`offsetof(struct ModernC, value)` 通常返回 0，`offsetof(struct ModernC, array)` 取决于前面成员的大小。
- **类似宏**：无直接类似，常用于内存布局分析

---

### 6. `alignof`

- **头文件**：`<stdalign.h>`
- **运算符**：`alignof(type)`
- **功能说明**：返回类型 `type` 对齐所需的字节数。
- **参数类型**：类型名
- **返回值类型**：`size_t`
- **示例**：`alignof(struct ModernC)` 返回整个结构体的最大对齐要求。
- **类似宏**：
  - `alignas`：用于声明对齐要求

---
# C语言格式化输出函数详解 (printf & fprintf)

## 1. 格式化输出函数的核心机制

### `printf` vs `fprintf`

- **`printf`**: 输出到标准输出流 `stdout`
- **`fprintf`**: 通过 `FILE* stream` 参数指定输出流（如文件、错误流 `stderr`）

### 共同特点

两个函数均使用**变参函数**（Variadic Function）设计，通过格式字符串（`format`）控制输出格式，后接数量不定的**尾随参数**（Trailing Arguments）。

### ⚠️ 关键约束：参数与格式符必须严格匹配

**Takeaway 8.4.4 #1**: 尾随参数的数量和类型必须与格式字符串中的 `%` 说明符**完全一致**，否则行为未定义（可能导致程序崩溃或数据错误）。

```c
int num = 42;
printf("%d", num);      // ✅ 正确：一个占位符对应一个参数
printf("%d %s", num);   // ❌ 错误：缺少第二个参数（字符串）
```
---
## 2. 格式说明符的组成结构

格式说明符遵循以下结构：`%[FF][WW][.PP][LL]SS`

| 组件 | 符号 | 描述 | 示例 |
|------|------|------|------|
| **标志（Flags）** | `FF` | 控制输出对齐、符号显示等<br/>• `-` 左对齐<br/>• `+` 强制显示正号<br/>• `0` 用零填充 | `%-10d`（左对齐10字符） |
| **宽度（Width）** | `WW` | 最小输出宽度（不足时填充空格/零） | `%8d`（至少占8字符） |
| **精度（Precision）** | `.PP` | 控制浮点数小数位数/字符串最大长度 | `%.2f`（保留2位小数） |
| **修饰符（Modifier）** | `LL` | 指定参数类型大小（避免类型不匹配） | `%lld`（对应 `long long`） |
| **说明符（Specifier）** | `SS` | **必选**，指定参数的数据类型 | `%d`（整数） |

---

## 3. 类型说明符详解 (Table 8.4.4)

### 整数类型

| 说明符 | 适用类型 | 用途 | 示例输出 |
|--------|----------|------|----------|
| `%d`, `%i` | 有符号整数 | 十进制整数 | `-42` |
| `%u` | 无符号整数 | 十进制正整数 | `42` |
| `%b` | 无符号整数 (C23新增) | **二进制输出** | `0b1010` |
| `%x`, `%X` | 无符号整数 | 十六进制（小写/大写） | `0xa`, `0xA` |

### 浮点数类型

| 说明符 | 适用类型 | 用途 | 特点 |
|--------|----------|------|------|
| `%f` | 浮点数 | 定点表示法 | 固定小数位数 |
| `%e`, `%E` | 浮点数 | 科学计数法 | 指数形式 |
| `%g`, `%G` | 浮点数 | 自动选择 `%f` 或 `%e` | **最短形式** |

### 其他类型

| 说明符 | 适用类型 | 用途 | 示例输出 |
|--------|----------|------|----------|
| `%s` | 字符串 | 输出字符数组 | `"Hello World"` |
| `%c` | 字符 | 输出单个字符 | `'A'` |
| `%p` | 指针 | 输出地址值 | `0x7ffe12345678` |

---
## 关于\n 与 fflush 的关系​
- ​避免在行尾添加空格，确保数据的一致性和可移植性
- ​互补性​：\n 是行缓冲的自动触发条件，fflush 是手动强制刷新手段。
- ​适用场景​：
​\n ​：常规文本行结束（如日志、提示信息）。
​**fflush**​：
- 进度条（printf("\rProgress: %d%%", i); fflush(stdout);）。
确保关键数据写入文件（如日志实时持久化）。
​重要区别​：fflush 对所有缓冲类型（全缓冲/行缓冲）有效，而 \n 仅触发行缓冲流的刷新。
- 额外提醒
C语言使用 \n 作为换行符的抽象表示，​独立于操作系统的具体实现。
Windows系统实际换行为 \r\n（回车+换行），
Unix/Linux系统仅为 \n，
经典Mac OS为 \r。
通过 \n，C标准库自动处理平台差异，开发者无需关心底层转换
- C23 新增占位符 %b​
C23 在 printf 中新增 %b 和 %B，用于直接输出二进制格式，结合 \n 可增强可读性

## 相关头文件和函数对照

| 头文件         | 主要内容                                                                   |
| -------------- | -------------------------------------------------------------------------- |
| `<stddef.h>`   | `offsetof`、`size_t`、`ptrdiff_t` 等                                      |
| `<stdalign.h>` | `alignof`、`alignas`                                                      |
| `<stdbit.h>`   | 位运算新函数（C23 新增）：`stdc_bit_width`、`stdc_has_single_bit` 等      |

---
# 数学计算标准库函数(numerical functions)
## C Mathematical Functions Reference

## Trigonometric Functions

| Function | Description |
|----------|-------------|
| **acos**, **acospi** | Arc cosine (divided by π) - C23 |
| **asin**, **asinpi** | Arc sine (divided by π) - C23 |
| **atan**, **atanpi** | Arc tangent (divided by π) - C23 |
| **atan2**, **atan2pi** | Arc tangent, two arguments (divided by π) - C23 |
| **cos**, **cospi** | Cosine function, cos x (cos πx) - C23 |
| **sin**, **sinpi** | Sine function, sin x (sin πx) - C23 |
| **tan**, **tanpi** | Tangent function, tan x (tan πx) - C23 |

## Hyperbolic Functions

| Function | Description |
|----------|-------------|
| **acosh** | Hyperbolic arc cosine |
| **asinh** | Hyperbolic arc sine |
| **atanh** | Hyperbolic arc tangent |
| **cosh** | Hyperbolic cosine |
| **sinh** | Hyperbolic sine |
| **tanh** | Hyperbolic tangent |

## Exponential and Logarithmic Functions

| Function | Description |
|----------|-------------|
| **exp** | e^x |
| **exp2** | 2^x |
| **expm1** | e^x - 1 |
| **log** | log_e x |
| **log10** | log₁₀ x |
| **log1p** | log_e (1 + x) |
| **log2** | log₂ x |
| **logb** | log_FLT_RADIX x as floating point |
| **ilogb** | ⌊log_FLT_RADIX x⌋ as integer |

## Power and Root Functions

| Function | Description |
|----------|-------------|
| **pow** | x^y |
| **pown** | x^n, n integer - C23 |
| **powr** | x^y, computed as e^(y log_e x) - C23 |
| **sqrt** | √x |
| **cbrt** | ∛x |
| **rootn** | ⁿ√x - C23 |
| **hypot** | √(x² + y²) |

## Rounding and Integer Functions

| Function | Description |
|----------|-------------|
| **ceil** | ⌈x⌉ |
| **floor** | ⌊x⌋ |
| **trunc** | sign(x) · ⌊\|x\|⌋ |
| **round**, **lround**, **llround** | sign(x) · ⌊\|x\| + 0.5⌋, integer |
| **roundeven** | sign(x) · ⌊\|x\| + 0.5⌋, floating point - C23 |
| **nearbyint** | Nearest integer using the current rounding mode |
| **rint**, **lrint**, **llrint** | Nearest integer using the current rounding mode |

## Floating-Point Manipulation

| Function | Description |
|----------|-------------|
| **frexp** | Significand and exponent |
| **ldexp** | x · 2^y |
| **scalbn**, **scalbln** | x · FLT_RADIX^y |
| **modf**[f\|l] | Integer and fractional parts |
| **copysign** | Copies the sign from y to x |

## Comparison and Classification

| Function | Description |
|----------|-------------|
| **fmax**, **fmaximum**[**_num**] | Floating-point maximum - C23 |
| **fmin**, **fminimum**[**_num**] | Floating-point minimum - C23 |
| **fmaximum_mag**[**_num**] | Floating-point value of maximal magnitude - C23 |
| **fminimum_mag**[**_num**] | Floating-point value of minimal magnitude - C23 |
| **fdim** | Positive difference |
| **fabs** | \|x\| for floating point |

## Floating-Point Status Functions

| Function | Description |
|----------|-------------|
| **fpclassify** | Classifies a floating-point value |
| **isfinite** | Checks if finite |
| **isinf** | Checks if infinite |
| **isnan** | Checks if NaN |
| **isnormal** | Checks if representation is normal |
| **signbit** | Checks if negative |

## Remainder and Division Functions

| Function | Description |
|----------|-------------|
| **fmod** | Remainder of floating-point division |
| **remainder** | Signed remainder of division |
| **remquo** | Signed remainder and the last bits of the division |

## Special Mathematical Functions

| Function | Description |
|----------|-------------|
| **erf** | Error function, (2/√π) ∫₀ˣ e^(-t²) dt |
| **erfc** | Complementary error function, 1 - (2/√π) ∫₀ˣ e^(-t²) dt |
| **tgamma** | Gamma function, Γ(x) |
| **lgamma** | log_e Γ(x) |

## C23 New Functions

### Rounded Arithmetic Operations
| Function | Description |
|----------|-------------|
| **fadd**, **dadd** | Rounded addition to **float** or **double** |
| **fsub**, **dsub** | Rounded subtraction to **float** or **double** |
| **fmul**, **dmul** | Rounded multiplication to **float** or **double** |
| **fdiv**, **ddiv** | Rounded division to **float** or **double** |

### Compound and Conversion Functions
| Function | Description |
|----------|-------------|
| **compoundn** | (1 + x)^n |
| **fma** | x · y + z |
| **fromfp**[f\|l] | Round to signed integer value with specific width |
| **ufromfp**[f\|l] | Round to unsigned integer value with specific width |

### Utility Functions
| Function | Description |
|----------|-------------|
| **canonicalize**[f\|l] | Canonicalize a floating point value |
| **nextup** | Next representable floating-point value (upward) |
| **nextafter** | Next representable floating-point value |
| **nexttoward** | Next representable floating-point value toward |
| **nan**[f\|l] | Not-a-number (NaN) of the corresponding type |

## 参考与推荐阅读

- [C23 标准文档 (N3096)](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf)
- [cppreference — stdbit.h (C23)](https://en.cppreference.com/w/c/numeric/stdbit)
- [cppreference — stdalign.h](https://en.cppreference.com/w/c/types/stdalign)
- [cppreference — stddef.h](https://en.cppreference.com/w/c/types/stddef)

---
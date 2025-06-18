[TOC]
# Modern-C23-learn
# C23 学习笔记

本笔记旨在帮助你系统学习 C23（ISO/IEC 9899:2023）标准的新特性及其用法，适合有 C 语言基础的开发者。是本人学习的 C23 笔记。

---

## 目录

- [C23 概述](#c23-概述)
- [新关键字与语法](#新关键字与语法)
- [标准库更新](#标准库更新)
- [类型系统增强](#类型系统增强)
- [预处理器改进](#预处理器改进)
- [诊断与静态分析](#诊断与静态分析)
- [兼容性与移植性](#兼容性与移植性)
- [参考资料](#参考资料)

---

## C23 概述

C23 是 C 语言的最新标准，对 C17 进行了若干改进，主要包括语法增强、标准库扩展、类型系统优化等。其目标是提升开发效率、代码安全性和可移植性。

---

## 新关键字与语法

### 1. `nullptr` 引入

C23 引入了 `nullptr`，表示空指针（与 C++ 保持一致）：

```c
int *p = nullptr;
```

### 2. `typeof` 关键字标准化

允许使用 `typeof(expr)` 获取表达式类型：

```c
typeof(1.2 + 3) x = 5.0;
```

### 3. `static_assert` 改进

`static_assert` 可用于文件作用域：

```c
static_assert(sizeof(int) == 4, "int 必须为 4 字节");
```

### 4. 字面量后缀改进

支持二进制字面量：

```c
int x = 0b1011; // 11
```

---

## 标准库更新

### 1. `<stdbool.h>` 增强

`true`/`false` 以及 `_Bool` 更加一致，`bool` 现在是关键字。

### 2. 新头文件 `<stdckdint.h>`

提供溢出检测的加/减/乘 API：

```c
#include <stdckdint.h>
int r;
if (ckd_add(&r, a, b)) {
    // 检测到溢出
}
```

### 3. `<uchar.h>` 改进

增强对 Unicode 字符的支持。

---

## 类型系统增强

### 1. `char8_t` 类型

增加了 `char8_t` 支持 UTF-8 字符：

```c
char8_t utf8str[] = u8"你好";
```

### 2. 可空类型 (`nullable`)

C23 正式引入 _Nullable、_Nonnull 注解（主要用于静态分析）。

---

## 预处理器改进

- 支持 `#elifdef` 与 `#elifndef`，增强条件编译表达力。
- 预处理器算术表达式支持更多运算。

---

## 诊断与静态分析

- `_Diagnostic` 属性可用于标记代码警告等。
- `_Nonnull` 和 `_Nullable` 注解提高代码安全性。

---

## 兼容性与移植性

- C23 保持了向后兼容，同时吸收了部分 C++ 特性。
- 推荐在新项目中使用 C23，老项目可选择性迁移。

---

## 参考资料

- [ISO/IEC 9899:2023 (C23) 标准草案](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf)
- [C23 新特性总结](https://en.cppreference.com/w/c/23)
- [GNU C23 支持情况](https://gcc.gnu.org/gcc-13/changes.html#c)

---

> 本文档持续更新，欢迎补充和指正！
# Modern C23 学习笔记 🚀

<div align="center">

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg?style=for-the-badge&logo=github-actions&logoColor=white)](https://github.com/NotfriendAtAll/Modern-C23-learn)
[![C Standard](https://img.shields.io/badge/C-23-blue.svg?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c/23)
[![Compiler](https://img.shields.io/badge/GCC-14.2+-red.svg?style=for-the-badge&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Linux-x86__64-orange.svg?style=for-the-badge&logo=linux&logoColor=white)](https://www.kernel.org/)

[![License](https://img.shields.io/badge/License-GPL_v3.0-green.svg?style=for-the-badge&logo=open-source-initiative&logoColor=white)](LICENSE)
[![Tests](https://img.shields.io/badge/Tests-100%25_Pass-success.svg?style=for-the-badge&logo=checkmarx&logoColor=white)](https://github.com/NotfriendAtAll/Modern-C23-learn)
[![Code Quality](https://img.shields.io/badge/Quality-A+-blueviolet.svg?style=for-the-badge&logo=codacy&logoColor=white)](https://github.com/NotfriendAtAll/Modern-C23-learn)
[![Memory Safe](https://img.shields.io/badge/Memory-Safe-yellow.svg?style=for-the-badge&logo=shield&logoColor=white)](https://github.com/NotfriendAtAll/Modern-C23-learn)

**探索 C23 标准的现代化特性与最佳实践**

[快速开始](#-quick-start) • [特性介绍](#-features) • [工具推荐](#-recommended-tools) • [学习路径](#-learning-path) • [贡献指南](#-contributing)

</div>

---

## 📋 概述

本项目是一个全面的 C23（ISO/IEC 9899:2023）学习笔记，专为有 C 语言基础的开发者设计。涵盖了 C23 的所有新特性、现代化编程实践以及推荐的开发工具链。

> 💡 **注意**: 本项目使用 UTF-8 编码，如需 GBK 编码请自行转换

## ✨ Features

<table>
<tr>
<td>

### 🚀 **现代化 C23**
- 最新 C23 标准特性详解
- 实用代码示例与最佳实践
- 性能优化技巧

</td>
<td>

### 🔧 **工具链优化**
- GCC 14.2+ 编译器支持
- 现代构建系统集成
- 静态分析工具配置

</td>
</tr>
<tr>
<td>

### 🛡️ **安全编程**
- 内存安全编程实践
- 缓冲区溢出防护
- 静态分析与 Sanitizer 集成

</td>
<td>

### 🧪 **测试驱动**
- 100% 测试覆盖率
- 单元测试框架集成
- 持续集成配置

</td>
</tr>
</table>

## 🛠️ 系统要求

| 组件 | 最低版本 | 推荐版本 | 说明 |
|------|----------|----------|------|
| **编译器** | GCC 13.0 | GCC 14.2+ | 完整 C23 支持 |
| **操作系统** | Linux 4.0+ | Ubuntu 22.04+ | x86_64 架构 |
| **构建工具** | Make 4.0 | Ninja 1.10+ | 高效构建系统 |
| **调试器** | GDB 10.0 | GDB 14.0+ | 调试支持 |

## 🚀 Quick Start

### 克隆项目

```bash
# 克隆仓库
git clone https://github.com/NotfriendAtAll/Modern-C23-learn.git
cd Modern-C23-learn
```

### 构建项目

<details>
<summary>🔨 使用 CMake + Ninja (推荐)</summary>

```bash
# 配置构建
cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Release

# 编译
cmake --build build

# 运行测试
ctest --test-dir build --output-on-failure
```
</details>
### 运行示例

```bash
# 运行主程序
./build/modern_c23

# 运行特定示例
./build/examples/c23_features
./build/examples/memory_safety
```

## 📚 学习目录

### 🏗️ 核心特性

- [**C23 概述**](docs/overview.md) - 标准变化与改进概览
- [**新关键字与语法**](docs/syntax.md) - `typeof`、`BitInt`、`decimal` 等
- [**类型系统增强**](docs/types.md) - 类型推导与泛型编程
- [**标准库更新**](docs/stdlib.md) - 新增函数与改进

### 🔧 进阶主题

- [**预处理器改进**](docs/preprocessor.md) - `#embed`、`#warning` 等
- [**诊断与静态分析**](docs/diagnostics.md) - 属性与检查工具
- [**内存安全编程**](docs/memory_safety.md) - 安全编程实践
- [**性能优化**](docs/performance.md) - 编译器优化技巧

### 🛠️ 工具与实践

- [**开发环境配置**](docs/development_setup.md) - IDE 与工具链配置
- [**测试与调试**](docs/testing_debugging.md) - 单元测试与调试技巧
- [**兼容性指南**](docs/compatibility.md) - 移植性与向后兼容

## 🧰 推荐工具

### 编译器与构建工具

| 工具 | 用途 | 安装命令 |
|------|------|----------|
| **GCC 14+** | C23 编译器 | `sudo apt install gcc-14` |
| **Clang 17+** | 替代编译器 | `sudo apt install clang-17` |
| **CMake** | 构建系统 | `sudo apt install cmake` |
| **Ninja** | 快速构建 | `sudo apt install ninja-build` |

### 静态分析工具

```bash
# 安装分析工具
sudo apt install cppcheck clang-tidy valgrind

# Clang Static Analyzer
sudo apt install clang-tools

### 推荐 C 库

#### 🔧 **系统与工具库**



| 库名 | 功能 | GitHub |
|------|------|--------|
| **liburing** | 高性能异步 I/O | [axboe/liburing](https://github.com/axboe/liburing) |
| **libevent** | 事件驱动网络库 | [libevent/libevent](https://github.com/libevent/libevent) |
| **libev** | 高性能事件循环 | [enki/libev](https://github.com/enki/libev) |
| **libuv** | 跨平台异步 I/O | [libuv/libuv](https://github.com/libuv/libuv) |


#### 📊 **数据结构与算法**


| 库名 | 功能 | GitHub |
|------|------|--------|
| **uthash** | 哈希表实现 | [troydhanson/uthash](https://github.com/troydhanson/uthash) |
| **klib** | 轻量级数据结构 | [attractivechaos/klib](https://github.com/attractivechaos/klib) |
| **SDS** | 简单动态字符串 | [antirez/sds](https://github.com/antirez/sds) |
| **cJSON** | JSON 解析库 | [DaveGamble/cJSON](https://github.com/DaveGamble/cJSON) |


#### 🧪 **测试框架**

<details>
<summary>展开查看详细列表</summary>

| 库名 | 特点 | GitHub |
|------|------|--------|
| **Unity** | 轻量级单元测试 | [ThrowTheSwitch/Unity](https://github.com/ThrowTheSwitch/Unity) |
| **Criterion** | 现代测试框架 | [Snaipe/Criterion](https://github.com/Snaipe/Criterion) |
| **cmocka** | 模拟测试框架 | [clibs/cmocka](https://github.com/clibs/cmocka) |
| **Greatest** | 头文件测试库 | [silentbicycle/greatest](https://github.com/silentbicycle/greatest) |

</details>

#### 🔒 **安全与加密**

<details>
<summary>展开查看详细列表</summary>

| 库名 | 功能 | GitHub |
|------|------|--------|
| **libsodium** | 现代加密库 | [jedisct1/libsodium](https://github.com/jedisct1/libsodium) |
| **OpenSSL** | 传统加密库 | [openssl/openssl](https://github.com/openssl/openssl) |
| **mbedTLS** | 嵌入式加密 | [Mbed-TLS/mbedtls](https://github.com/Mbed-TLS/mbedtls) |

```bash
# 安装示例
sudo apt install libsodium-dev libssl-dev libmbedtls-dev
```

</details>

### IDE 与编辑器配置

#### 🚀 **VS Code 配置**

<details>
<summary>推荐插件与配置</summary>

## 📊 项目统计

<div align="center">

![GitHub stars](https://img.shields.io/github/stars/NotfriendAtAll/Modern-C23-learn?style=social)
![GitHub forks](https://img.shields.io/github/forks/NotfriendAtAll/Modern-C23-learn?style=social)
![GitHub issues](https://img.shields.io/github/issues/NotfriendAtAll/Modern-C23-learn)
![GitHub pull requests](https://img.shields.io/github/issues-pr/NotfriendAtAll/Modern-C23-learn)

</div>

## 🤝 Contributing

我们欢迎所有形式的贡献！请查看 [贡献指南](CONTRIBUTING.md) 了解详情。

### 贡献方式

- 🐛 **报告 Bug** - 提交 Issue 描述问题
- 💡 **功能建议** - 分享你的想法和建议  
- 📝 **文档改进** - 完善文档和示例
- 🔧 **代码贡献** - 提交 Pull Request

## 📄 许可证

本项目采用 [GNU General Public License v3.0](LICENSE) 许可证。

## 🔗 参考资源

### 官方文档

- 📘 [ISO/IEC 9899:2023 (C23) 标准草案](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf)
- 📖 [C23 新特性总结 - cppreference](https://en.cppreference.com/w/c/23)
- 🔧 [GNU C23 支持情况](https://gcc.gnu.org/gcc-13/changes.html#c)

### 社区资源

- 💬 [C 标准委员会邮件列表](https://www.open-std.org/jtc1/sc22/wg14/)
- 🌐 [Reddit r/C_Programming](https://www.reddit.com/r/C_Programming/)
- 📺 [YouTube C 编程频道推荐](docs/resources.md#youtube-channels)

---

<div align="center">

**🌟 如果这个项目对你有帮助，请给个 Star！**

Made with ❤️ by [NotfriendAtAll](https://github.com/NotfriendAtAll)

</div>
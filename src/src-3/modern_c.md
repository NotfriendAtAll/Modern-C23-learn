[TOC]
## string.h 函数
**strlen**
函数，需运行时计算，返回实际字符数​（不含 \0）,仅接受 char* 参数，且必须以 \0 结尾
```bash
size_t my_strlen(const char* str) {
    size_t count = 0;
    while (*str++) count++; // 遇 '\0' 终止
    return count;
}
or
size_t my_strlen(const char* str) {
    const char* start = str;
    while (*str) str++; // 移动到 '\0' 处
    return str - start; // 地址差即长度
}
若不确定字符数组是否以 \0 终止，优先使用 memchr 替代 strlen
size_t safe_strlen(const char *s, size_t max_len) {  
    const char *end = memchr(s, '\0', max_len);  
    return end ? (size_t)(end - s) : max_len;  
}  
```
- 警告
**超长扫描时间**​：strlen 等函数因未遇到 \0 而持续扫描内存，导致性能骤降
​**段错误**（Segmentation Violation）​​：函数越界访问非法内存（如数组末尾之后），触发系统保护机制
**​数据污染​**：strcpy 等函数写入越界内存，破坏其他变量或程序状态（如覆盖相邻数组）
***
​**sizeof**
编译时运算符，返回数组或类型的内存占用字节数​（含 \0 及未使用的空间）
## 常用字符串与内存操作函数

### 1. 内存操作函数

| 函数                | 功能               | 关键参数           | 注意事项                                               |
|---------------------|--------------------|--------------------|--------------------------------------------------------|
| `memcpy(dest, src, len)`   | 复制指定字节        | `len`：需复制的字节数 | 要求 `dest` 与 `src` 内存不重叠，否则行为未定义         |
| `memcmp(s1, s2, len)`      | 按字节比较内存内容   | `len`：比较的字节数   | 返回差值（s1>s2为正，s1<s2为负，相等为0）               |
| `memchr(s, c, len)`        | 查找字符 `c`        | `len`：搜索范围       | 返回首次出现位置的指针，未找到返回 `NULL`               |
---
- 使用 memchr 和 memcmp 实现边界安全的 strcmp
```bash
int safe_strcmp(const char *s1, const char *s2, size_t max_len) {  
    size_t len1 = safe_strlen(s1, max_len);  // 使用前述安全长度函数  
    size_t len2 = safe_strlen(s2, max_len);  
    size_t min_len = len1 < len2 ? len1 : len2;  

    // 比较前 min_len 字节  
    int cmp = memcmp(s1, s2, min_len);  
    if (cmp != 0) return cmp;  

    // 若共同部分相同，比较长度差异  
    return (int)(len1 - len2);  
}  
```

### 2. 字符串（str）系列函数：操作以 `\0` 结尾的字符串

| 函数                    | 功能                 | 关键特性                         | 安全风险/注意事项                                   |
|-------------------------|----------------------|-----------------------------------|------------------------------------------------------|
| `strlen(s)`             | 计算字符串长度       | 从首字符遍历到 `\0`（不含`\0`）   | 未终止则越界访问（未定义行为）                       |
| `strcpy(dest, src)`     | 复制整个字符串       | 自动复制到 `\0` 结束              | `dest` 空间不足时缓冲区溢出（高危）                  |
| `strcmp(s1, s2)`        | 按ASCII比较字符串    | 遇 `\0` 停止比较                  | 不兼容本地化排序（如 ä ≠ a）                         |
| `strcoll(s1, s2)`       | 本地化规则比较       | 依赖系统区域设置                  | 需提前调用 `setlocale()`                             |
| `strchr(s, c)`          | 查找字符首次出现     | 返回指针或 `NULL`                  | 类似 `memchr` 但需 `\0` 终止                         |
| `strspn(s, accept)`     | 计算全匹配长度       | 统计 s 中连续属于 accept 的字符数  | 常用于解析结构化数据                                 |
---
- 提醒
**旧版问题​**：strchr 的原型为 char *strchr(const char *s, int c)，当传入 const char* 时返回非 const 指针，可能破坏常量性约定。
​**C23 解决方案**​：
通过 ​类型泛型宏（Type-Generic Macro）​​ 重新定义 strchr，使其根据输入类型自动推导返回类型：
若输入 const char*，返回 const char*；
若输入 char*，返回 char*

### 3. 动态字符串函数（C23 新增）

- `strdup(src)`：复制字符串并动态分配内存（需手动 `free()`）

    ```c
    char *copy = strdup("Hello");
    free(copy);  // 必须释放内存
    ```

- `strndup(src, len)`：类似但限制最大复制长度，避免长字符串风险

---

## 关键安全实践与常见错误

### 缓冲区溢出防御

- **危险操作**：`strcpy(dest, src)` 若 `src` 长度 > `dest` 容量，覆盖相邻内存，极易造成安全漏洞。
- **安全替代**：

    ```c
    strncpy(dest, src, dest_size - 1);  // 限制长度
    dest[dest_size - 1] = '\0';         // 手动终止
    // 或使用动态分配（strdup）
    ```

---

### 未终止字符串的后果

- `strlen` 或 `strcpy` 对非 `\0` 结尾的数组（如 `char s[3] = "abc";`）会越界访问，导致崩溃或数据污染。

---

### 编码兼容性问题

- ASCII 无法处理多字节字符（如中文）。如需国际化，应使用宽字符（`wchar_t`）或 UTF-8 库（如 iconv）。

---

##  总结与最佳实践

### 核心原则

- **始终确保字符串以 `\0` 终止**（初始化数组时预留空间）。
- **优先使用安全函数**：`strncpy` 替代 `strcpy`，`strncat` 替代 `strcat`。
- **动态内存管理**：`strdup` 后必须 `free`，避免内存泄漏。

### 跨平台兼容性

- 本地化比较用 `strcoll`，非 ASCII 文本避免直接操作字节。
- 敏感操作（如网络通信）应显式处理编码转换。

---

> **关键点**：C 字符串的高效与风险并存，安全依赖于开发者对 `\0` 终止、内存边界和编码规则的严格遵守。通过函数的安全封装和动态内存管理，可大幅降低隐患。
```bash
Linux下 输出
字符串: hello
strlen(s): 5
memcpy 结果: world
memcmp(a, b, 3): -1
memchr: 'l' 在 "hello" 的第 2 个位置
strcpy 结果: hello
strcmp("abc", "abd"): -1
strcoll("abc", "abd"): -1
strchr: 'e' 在 "hello" 的第 1 个位置
strspn("abc123", "abc"): 3
strdup 结果: hello
strndup 结果: abc
```
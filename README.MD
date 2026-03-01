# GNU libiconv 1.18

GNU libiconv - 字符集转换库，支持在不同字符编码之间进行转换。

这是针对**原生构建**优化的版本，提供了 CMake 和 Visual Studio 项目文件，无需 Cygwin/MSYS2 环境即可在 Windows 上构建。

## 特性

- 支持 200+ 种字符编码
- 兼容 POSIX iconv API
- 跨平台支持：Windows、Linux、macOS

## 构建方式

### Windows

#### 方式 1：CMake（推荐）

```bash
cmake -B build -A x64
cmake --build build --config Release
```

#### 方式 2：Visual Studio 项目

预配置的 Visual Studio 解决方案位于 `msvc/` 目录：

| 目录      | Visual Studio | 工具集  |
|-----------|---------------|---------|
| `msvc/16` | VS2019        | v142    |
| `msvc/17` | VS2022        | v143    |
| `msvc/18` | VS2026        | v145    |

直接用对应版本的 Visual Studio 打开 `libiconv.sln` 即可构建。

**输出文件：**
- `charset.lib` - 静态库
- `iconv.dll` / `iconv.lib` - 动态库及导入库

### Linux / macOS

> **注意**：glibc (Linux) 和 macOS 系统库已内置 iconv。为避免冲突，建议安装到独立目录。

#### 前置依赖

```bash
# Ubuntu/Debian
sudo apt-get install -y build-essential gettext

# CentOS/RHEL/Fedora
sudo yum install -y gcc make gettext

# macOS (使用 Homebrew)
brew install gettext
```

#### 方式 1：autoconf（推荐）

```bash
# 配置（默认安装到 /usr/local）
bash ./configure

# 或指定安装路径
bash ./configure --prefix=/opt/libiconv

# 编译
make

# 安装
sudo make install
```

#### 方式 2：CMake

```bash
cmake -B build -DCMAKE_INSTALL_PREFIX=/opt/libiconv
cmake --build build
sudo cmake --install build
```

**使用时指定路径：**
```bash
# 编译时
gcc -I/opt/libiconv/include -L/opt/libiconv/lib -liconv your_code.c

# 运行时
export LD_LIBRARY_PATH=/opt/libiconv/lib:$LD_LIBRARY_PATH  # Linux
export DYLD_LIBRARY_PATH=/opt/libiconv/lib:$DYLD_LIBRARY_PATH  # macOS
```

## CMake 选项

| 选项 | 默认值 | 说明 |
|------|--------|------|
| `BUILD_SHARED_LIBS` | `ON` | 构建动态库 |
| `ICONV_ENABLE_EXTRA` | `OFF` | 启用额外的编码支持 |

示例：
```bash
cmake -B build -DICONV_ENABLE_EXTRA=ON
```

## 使用

### CMake 项目集成

```cmake
find_package(iconv REQUIRED)
target_link_libraries(your_target PRIVATE Iconv::Iconv)
```

### pkg-config

```bash
pkg-config --cflags --libs iconv
```

### 代码示例

```c
#include <iconv.h>

iconv_t cd = iconv_open("UTF-8", "GBK");
if (cd != (iconv_t)-1) {
    char *inbuf = "你好";
    size_t inbytesleft = strlen(inbuf);
    char outbuf[256];
    char *outptr = outbuf;
    size_t outbytesleft = sizeof(outbuf);
    
    iconv(cd, &inbuf, &inbytesleft, &outptr, &outbytesleft);
    iconv_close(cd);
}
```

## 目录结构

```
libiconv-1.18/
├── CMakeLists.txt      # CMake 构建配置
├── lib/                # libiconv 核心源码
├── libcharset/         # 字符集检测库
├── src/                # iconv 命令行工具
├── msvc/               # Visual Studio 项目
│   ├── 16/             # VS2019
│   ├── 17/             # VS2022
│   └── 18/             # VS2026
└── cmake/              # CMake 包配置文件
```

## 许可证

GNU LGPL v2.1 - 详见 [COPYING.LIB](COPYING.LIB)

## 链接

- 官方主页：https://www.gnu.org/software/libiconv/
- 文档：https://www.gnu.org/software/libiconv/documentation/libiconv-1.18/

# 指出使用的终端
#!/bin/bash

# 在终端弹出提示帮助信息
echo "=== CryptoTool 构建脚本 ==="

# 创建必要的目录
echo "创建构建目录..."
mkdir -p build
mkdir -p bin

# 进入build目录
cd build

# 运行CMake生成Makefile
echo "生成构建文件..."
if cmake ..; then
    echo "CMake 配置成功"
else
    echo "CMake 配置失败!"
    cd ..
    exit 1
fi

# 编译项目
echo "编译项目..."
if make ; then
    echo "编译成功!"
else
    echo "编译失败!"
    cd ..
    exit 1
fi

# 返回项目根目录
cd ..

# 检查是否编译成功
if [ -f "bin/CryptoTool" ]; then
    echo ""
    echo "✅ 构建完成!"
    echo "📁 可执行文件: bin/CryptoTool"
    echo ""
    echo "现在运行程序:"
    echo "请继续输入：./bin/CryptoTool"
else
    echo "❌ 构建失败 - 未找到可执行文件"
    exit 1
fi

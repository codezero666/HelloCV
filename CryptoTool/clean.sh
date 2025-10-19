# 指出使用的终端
#!/bin/bash

echo "=== 清理构建文件 ==="

# read	读取选项
# -p "提示文本"	显示提示信息
# -n 1	只读取一个字符
# -r 原始模式，不解释反斜杠转义字符
read -p "确定要删除 build 和 bin 目录吗？(y/n): " -n 1 -r
echo # 换行
# $REPLY是read命令的默认变量，存储用户输入
# 这是正则表达式写法
if [[ $REPLY =~ ^[Yy]$ ]]; then
    echo "删除 build 目录..."
    rm -rf build
    echo "删除 bin 目录..."
    rm -rf bin
    echo "✅ 清理完成!"
else
    echo "❌ 取消清理"
fi

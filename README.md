# 第二周  
Docker：https://www.yuque.com/codezero-kv7wr/byma8n/bmg0puiv3fl5tse7#  
Cmake：https://www.yuque.com/codezero-kv7wr/byma8n/wkykb7p3d1qbkt86#  
简易的文本加密解密工具实现：https://www.yuque.com/codezero-kv7wr/byma8n/xpee1sag8p9sq23b  

# 程序使用方法  
## 1、编译  
（推荐）可以使用自动脚本编译：在主文件夹内打开bush，输入./build,sh  
也可以手动创建build文件夹，cd build，然后cmake ..，再make  
## 2、运行
建议进入/bin内打开终端运行，便于后期文件加密解密输入相对路径  
也可以./bin/CryptoTool运行  
## 3、按照菜单提示进行输入数字选择功能  
初始时默认使用凯撒加密，也可以根据选项更换加密方式  
## 4、关于文件加密解密的使用  
首先要将需要加密/解密的文件放入bin/目录下（与可执行文件同级）  
然后按照命令提示输入相对路径：  
如果你是在主目录文件内./bin/CryptoTool运行的，输入文件路径需要写./bin/xxx.txt  
如果你是在bin/目录下，输入文件路径需要写xxx.txt  
输出文件路径建议也写在bin/目录下（与可执行文件同级）
## 5、注意事项
使用凯撒加密时密钥建议使用非负数或纯字符串  
本代码采用简单的XOR加密，部分情况可能输出空字符  
反转加密会索取用不上的密钥  

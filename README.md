# 第三周
## 语雀文档
OpenCV4.5学习：https://www.yuque.com/codezero-kv7wr/byma8n/nyka649oenze4boz#  
OpenCV小测试：https://www.yuque.com/codezero-kv7wr/byma8n/rtkrayg2ox7yg2kq  
## 程序实现思路（简要）
1、先根据红绿色HSV范围筛选出2个蒙版  
2、再标出轮廓  
3、根据轮廓过滤掉除圆形灯外的元素  
4、进行方框的显示  
## 程序使用方法  
### 1、编译  
（推荐）可以使用自动脚本编译：在主文件夹内打开bush，输入./build,sh  
也可以手动创建build文件夹，cd build，然后cmake ..，再make  
### 2、运行
可以按脚本提示按键运行  
也可以手动进入bin目录内再运行  
### 3、注意事项
运行时会快速播放预览视频  
预览视频播放完后avi视频便生成成功，在video目录内  

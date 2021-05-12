:: 文件名: make.bat
echo off
mingw32-make -f makefile1
echo 文件编译完毕
mingw32-make -f makefile1 clean
echo 已经删除中间文件
main.exe
echo 文件执行完毕
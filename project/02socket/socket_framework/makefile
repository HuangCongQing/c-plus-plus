all:client server 01client_base_framework 01server_base_framework mpserver demo47_biz mpserver_biz mtserver_biz demo47_timer

# base  无封装
client:client.cpp
	g++ -g -o client client.cpp

# base 无封装
server:server.cpp
	g++ -g -o server server.cpp

# 客户端   ./01client_base_framework 127.0.0.1  5005
01client_base_framework:01client_base_framework.cpp
	g++ -g -o 01client_base_framework 01client_base_framework.cpp _freecplus.cpp

# 服务端   ./01server_base_framework 5005
01server_base_framework:01server_base_framework.cpp
	g++ -g -o 01server_base_framework 01server_base_framework.cpp _freecplus.cpp

# 多进程server
mpserver:mpserver.cpp
	g++ -g -o mpserver mpserver.cpp _freecplus.cpp

#  业务示例 client
demo47_biz:demo47_biz.cpp
	g++ -g -o demo47_biz demo47_biz.cpp _freecplus.cpp

# 多进程server
mpserver_biz:mpserver_biz.cpp
	g++ -g -o mpserver_biz mpserver_biz.cpp _freecplus.cpp

# 多线程server
mtserver_biz:mtserver_biz.cpp
	g++ -g -o mtserver_biz mtserver_biz.cpp _freecplus.cpp -lpthread

# 增加了业务示例和计时功能 client
demo47_timer:demo47_timer.cpp
	g++ -g -o demo47_timer demo47_timer.cpp _freecplus.cpp

# 删除编译文件
clean:
	rm -rf client server 01client_base_framework 01server_base_framework mpserver demo47_biz mpserver_biz mtserver_biz demo47_timer

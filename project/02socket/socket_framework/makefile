all:client server demo47 demo48 mpserver demo47_biz mpserver_biz mtserver_biz demo47_timer

client:client.cpp
	g++ -g -o client client.cpp

server:server.cpp
	g++ -g -o server server.cpp

# 客户端
01client_base_framework:01client_base_framework.cpp
	g++ -g -o 01client_base_framework 01client_base_framework.cpp _freecplus.cpp

# 服务端
01server_base_framework:01server_base_framework.cpp
	g++ -g -o 01server_base_framework 01server_base_framework.cpp _freecplus.cpp

mpserver:mpserver.cpp
	g++ -g -o mpserver mpserver.cpp _freecplus.cpp

demo47_biz:demo47_biz.cpp
	g++ -g -o demo47_biz demo47_biz.cpp _freecplus.cpp

mpserver_biz:mpserver_biz.cpp
	g++ -g -o mpserver_biz mpserver_biz.cpp _freecplus.cpp

mtserver_biz:mtserver_biz.cpp
	g++ -g -o mtserver_biz mtserver_biz.cpp _freecplus.cpp -lpthread

demo47_timer:demo47_timer.cpp
	g++ -g -o demo47_timer demo47_timer.cpp _freecplus.cpp

clean:
	rm -rf client server demo47 demo48 mpserver demo47_biz mpserver_biz mtserver_biz demo47_timer

interface: interface.c
	gcc -fPIC -I ../lib/ -c ./cc/Config.c
	gcc -fPIC -I ../lib/ -c ./cc/Res.c
	gcc -fPIC -I ../lib/ -c interface.c
	gcc -shared -I ../lib/ -o interface.dll interface.o Config.o Res.o

scene1: scene1.cs
	mcs scene1.cs

main: main.c interface.c
	gcc -g -I ../lib/ main.c interface.c cc/Config.c cc/Res.c
	

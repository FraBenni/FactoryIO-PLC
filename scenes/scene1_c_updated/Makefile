testing:
	gcc -I ../lib/ -fpic -c ladder/Config.c -o obj/Config.o
	gcc -I ../lib/ -fpic -c ladder/Res.c -o obj/Res.o
	gcc -I ../lib/ -I ./ladder/ -fpic -c src/interface.c -o obj/interface.o
	gcc -shared -o ./bin/interface.dll obj/interface.o obj/Config.o obj/Res.o
	gcc -I ../lib/ -I ./ladder/ src/main.c src/interface.c ladder/Config.c ladder/Res.c

windows: interface.c
	x86_64-w64-mingw32-gcc -I ../lib/ -c ./cc/Config.c
	x86_64-w64-mingw32-gcc -I ../lib/ -c ./cc/Res.c
	x86_64-w64-mingw32-gcc -I ../lib/ -c interface.c
	x86_64-w64-mingw32-gcc -shared -I ../lib/ -o interface.dll interface.o Config.o Res.o
	

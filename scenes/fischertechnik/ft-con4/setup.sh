base_dir="/mnt/c/Users/Matt Potok/Documents/Research/Smart Manufacturing/factory-io"
iec=$base_dir/lib/iec

echo "Compiling sources"
x86_64-w64-mingw32-gcc -I "$iec" -c "./ladder/Config0.c" -o "./obj/Config.obj"
x86_64-w64-mingw32-gcc -I "$iec" -c "./ladder/Res0.c" -o "./obj/Res.obj"
x86_64-w64-mingw32-gcc -I "$iec" -I "./ladder" -c "./src/interface.c" -o "./obj/interface.obj"
x86_64-w64-mingw32-gcc -shared -I "$iec" "./obj/interface.obj" "./obj/Config.obj" "./obj/Res.obj" -o "../bin/ft-con4.dll"

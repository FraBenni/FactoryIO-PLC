base_dir="/mnt/c/Users/Matt Potok/Documents/Research/Smart Manufacturing/factory-io"
scene=$base_dir/scenes/$1

if [ ! -d "$scene" ]; then
	echo "Scene $scene doesn't exist."
fi

# Compile sources
bin=$scene/bin
obj=$scene/obj
ladder=$scene/ladder
src=$scene/src

iec=$base_dir/lib/iec

mkdir -p "$bin"
mkdir -p "$obj"

echo "Compiling sources"
x86_64-w64-mingw32-gcc -I "$iec" -c "$ladder/Config.c" -o "$obj/Config.obj"
x86_64-w64-mingw32-gcc -I "$iec" -c "$ladder/Res.c" -o "$obj/Res.obj"
x86_64-w64-mingw32-gcc -I "$iec" -I "$ladder" -c "$src/interface.c" -o "$obj/interface.obj"
x86_64-w64-mingw32-gcc -shared -I "$iec" "$obj/interface.obj" "$obj/Config.obj" "$obj/Res.obj" -o "$bin/interface.dll"

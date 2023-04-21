#! /bin/sh

clear
cd /MODULE-ORIENTED-C

echo "Building c-lib/module-a/module-a.0.0.0"
cmake ./c-lib/src/module-a/module-a.0.0.0 -B./c-lib/build/module-a/module-a.0.0.0
cmake --build ./c-lib/build/module-a/module-a.0.0.0 --target all -j 4
cmake --install ./c-lib/build/module-a/module-a.0.0.0 --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.0.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.0.so

echo "Building c-lib/module-a/module-a.0.0.1"
cmake ./c-lib/src/module-a/module-a.0.0.1 -B./c-lib/build/module-a/module-a.0.0.1
cmake --build ./c-lib/build/module-a/module-a.0.0.1 --target all -j 4
cmake --install ./c-lib/build/module-a/module-a.0.0.1 --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.1.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.1.so

echo "Building c-lib/module-a"
cmake ./c-lib/src/module-a -B./c-lib/build/module-a
cmake --build ./c-lib/build/module-a --target all -j 4
cmake --install ./c-lib/build/module-a --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.so
objdump -T ./c-lib/lib/c-lib-module-a.so

echo "Building c-server"
cmake ./c-server -B./c-server/build
cmake --build ./c-server/build --target all -j 4
cmake --install ./c-server/build --prefix=./c-server
./c-server/bin/c-server
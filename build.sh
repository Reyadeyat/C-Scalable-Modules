#! /bin/sh

clear
cd /MODULE-ORIENTED-C

echo "Building c-lib/module-a/module-a.0.0.0"
cmake ./c-lib/src/module-a/module-a.0.0.0 -B./c-lib/src/module-a/module-a.0.0.0/build
cmake --build ./c-lib/src/module-a/module-a.0.0.0/build --target all -j 4
cmake --install ./c-lib/src/module-a/module-a.0.0.0/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.0.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.0.so

echo "Building c-lib/module-a/module-a.0.0.1"
cmake ./c-lib/src/module-a/module-a.0.0.1 -B./c-lib/src/module-a/module-a.0.0.1/build
cmake --build ./c-lib/src/module-a/module-a.0.0.1/build --target all -j 4
cmake --install ./c-lib/src/module-a/module-a.0.0.1/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.1.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.1.so

echo "Building c-lib/module-a"
cmake ./c-lib/src/module-a -B./c-lib/src/module-a/build
cmake --build ./c-lib/src/module-a/build --target all -j 4
cmake --install ./c-lib/src/module-a/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.so
objdump -T ./c-lib/lib/c-lib-module-a.so

echo "Building c-server"
cmake ./c-server -B./c-server/build
cmake --build ./c-server/build --target all -j 4
cmake --install ./c-server/build --prefix=./c-server
./c-server/bin/c-server
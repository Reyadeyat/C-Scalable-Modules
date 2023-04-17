#! /bin/sh

clear
cd /linux/MODULE-ORIENTED-C

echo "Building c-lib/mdule_a/module_a_0_0_0"
cmake ./c-lib/src/module_a/module_a_0_0_0 -B./c-lib/src/module_a/module_a_0_0_0/build
cmake --build ./c-lib/src/module_a/module_a_0_0_0/build --target all -j 4
cmake --install ./c-lib/src/module_a/module_a_0_0_0/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.0.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.0.so

echo "Building c-lib/mdule_a/module_a_0_0_1"
cmake ./c-lib/src/module_a/module_a_0_0_1 -B./c-lib/src/module_a/module_a_0_0_1/build
cmake --build ./c-lib/src/module_a/module_a_0_0_1/build --target all -j 4
cmake --install ./c-lib/src/module_a/module_a_0_0_1/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib-module-a.0.0.1.so
objdump -T ./c-lib/lib/c-lib-module-a.0.0.1.so

echo "Building c-lib/mdule_a"
cmake ./c-lib/src/module_a -B./c-lib/src/module_a/build
cmake --build ./c-lib/src/module_a/build --target all -j 4
cmake --install ./c-lib/src/module_a/build --prefix=./c-lib
readelf -s ./c-lib/lib/c-lib.so
objdump -T ./c-lib/lib/c-lib.so

echo "Building c-server"
cmake ./c-server -B./c-server/build
cmake --build ./c-server/build --target all -j 4
cmake --install ./c-server/build --prefix=./c-server
./c-server/bin/c-server
# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Follow the instructions explained in the beginning of file ejemplo1.c for compiling with gcc and g++ (you can try also clang). 

## ejemplo2.c. Program Instrumentation

Find the memory errors presented in file ejemplo2 using gcc instrumentation option **AddressSanitizer (ASan)**.
Explain in this file each error.

WARNING 1: linea 23
La función intenta imprimir en pantalla el puntero s después de que éste haya sido liberado en memoria

WARNING 2: linea 24
Sucede el mismo problema, la función copia al puntero s un String, pero éste no se puede copiar debido a que
el puntero s ha liberado su espacio de memoria

WARNING 3: linea 28
El puntero s ha reservado 18 bytes en memoria, pero se intenta copiar el String "Welcome Sanitizer!", que ocupa 19 bytes,
por lo que se produce un desbordamiento al intentar escribir en una posición que no está reservada para el puntero
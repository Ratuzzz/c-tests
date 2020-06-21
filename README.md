MY_DEFINE
MyType
my_lib_function()
my_variable

----

Source : https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
ar -> Static library ".a" (unix) ".lib" (Windows)
Shared library ".so" (unix) ".dll" (Windows)

Included headers must be in the path indicated by "-I"
Libraries are located with "-L" (Same as env variable 'LIBRARY_PATH')
They are listed with "-l"


https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
Create shared lib 
gcc -c -Wall -Werror -fpic src/my_lib.c -Iinclude
gcc -shared -o my_lib.so my_lib.o

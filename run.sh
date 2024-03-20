set -e

rm -f main

# -std=c++2b enables experimental c++23 support
g++ \
    -std=c++2b \
    -Wall -Wextra -Werror \
    -o main main.cpp \
    -I./external/include/ -L./external/lib/ \
    -lSDL2

# The -I flag tells g++ where to look for the header files
# The -L flag where to look for the library
# and the -l flag specifies the name of the library
# g++ -Wall -Wextra -Werror -o main main.c -I./external/include/ -L./external/lib/ -l:lib<LIB_NAME>.a # staticlink
# g++ -Wall -Wextra -Werror -o main main.c -I./external/include/ -L./external/lib/ -l<LIB_NAME> # dynlink

# LD_LIBRARY_PATH not required for staticlib
# export LD_LIBRARY_PATH=./external/lib/:$LD_LIBRARY_PATH

./main

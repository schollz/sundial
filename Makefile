CC := gcc
OUT := sundial
SRC := sundial.c
C_STANDARD := c11
FLAGS := -std=$(C_STANDARD) -lm -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

compile:
	@echo "Compiling. Please wait..."
	@${CC} ${SRC} -o ${OUT} ${FLAGS}
	

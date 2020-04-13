all: program

program: main FuncionesCC
	gcc -o parcial2 main.o FuncionesCC.o

funcionesCC: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c

main: main.c FuncionesCC.h
	gcc -c main.c
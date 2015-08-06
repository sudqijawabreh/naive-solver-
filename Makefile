flags= -std=c11 -g


all:test

test: solving_07_01.o solving_07_02.o solving_08_01.o solving_09_01.c solving_01_04_modify.o main.o  vecInt.o
	gcc -o test  $^ $(flags) 

%.o: %.c
	gcc -o $@ -c $< $(flags)


clean: 
	rm -rf *o
	
mrproper: clean
	rm -rf test

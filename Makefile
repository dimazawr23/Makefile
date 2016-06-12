main: ./obj/main.o ./obj/lab.o ./bin
	gcc ./obj/main.o ./obj/lab.o -Wall -o ./bin/main

./obj/main.o: ./src/main.c ./obj
	gcc -c ./src/main.c -Wall -o ./obj/main.o

./obj/lab.o: ./src/lab.c ./obj
	gcc -c ./src/lab.c -Wall -o ./obj/lab.o

./bin:
	mkdir bin

./obj:
	mkdir obj

.PHONY: clean
clean:
	rm -f -r bin obj 

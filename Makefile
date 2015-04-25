compile=gcc -Wall -Wpedantic

bin/tinydex-tokens: src/tinydex-tokens.c obj/record.o obj/io.o
	$(compile) -o bin/tinydex-tokens src/tinydex-tokens.c\
		obj/record.o obj/io.o


obj/record.o: src/record.c src/record.h obj/io.o
	$(compile) -o obj/record.o -c src/record.c


obj/io.o: src/io.c src/io.h
	$(compile) -o obj/io.o -c src/io.c

bin/tinydex-tokens: src/tinydex-tokens.c obj/record.o obj/io.o
	gcc -o bin/tinydex-tokens src/tinydex-tokens.c obj/record.o obj/io.o


obj/record.o: src/record.c src/record.h obj/io.o
	gcc -o obj/record.o -c src/record.c


obj/io.o: src/io.c src/io.h
	gcc -o obj/io.o -c src/io.c

all: ./bin/user clean

./bin/user: ./obj/tad-rec-ord.o
	mkdir -p ./bin && gcc -o ./bin/user ./user.c ./obj/tad-lista-dupla-enc-nord.o -g

./obj/tad-rec-ord.o:
	mkdir -p ./obj && gcc -o ./obj/tad-lista-dupla-enc-nord.o -c tad-lista-dupla-enc-nord.c -g

clean:
	rm -rf ./obj/*

all: ./bin/user clean

./bin/user: ./obj/tad-rec-ord.o
	mkdir -p ./bin && gcc -o ./bin/user ./user.c ./obj/tad-estatica-nord.o -g

./obj/tad-rec-ord.o:
	mkdir -p ./obj && gcc -o ./obj/tad-estatica-nord.o -c tad-estatica-nord.c -g

clean:
	rm -rf ./obj/*

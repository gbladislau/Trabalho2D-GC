
all: lib game

lib:
	cd ./lib
	make all

game: lib
	g++ -o trabalhoCG *.cpp 

clean:
	rm -f trabalhoCG *.o

run: clean game
	./trabalhoCG
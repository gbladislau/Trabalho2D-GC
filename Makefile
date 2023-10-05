
all: game

game: clean
	g++ -o trabalhoCG *.cpp -lGL -lGLU -lglut -lm

clean:
	rm -f trabalhoCG *.o

run: clean game
	./trabalhoCG
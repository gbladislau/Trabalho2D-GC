
all: game

game: clean
	g++ -o trabalhoCG *.cpp -lGL -lGLU -lglut -lm

clean:
	rm -f trabalhoCG trabalhoCG_d *.o

debug: clean
	g++ -o trabalhoCG_d *.cpp -lGL -lGLU -lglut -lm -g
	gdb ./trabalhoCG_d

run: clean game
	./trabalhoCG
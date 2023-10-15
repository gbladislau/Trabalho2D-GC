
all: game

game: clean
	g++ -o trabalhocg ./src/*.cpp -lGL -lGLU -lglut -lm

clean:
	rm -f trabalhocg trabalhocg_d *.o

debug: clean
	g++ -o trabalhocg_d ./src/*.cpp -lGL -lGLU -lglut -lm -g
	gdb ./trabalhocg_d

run: clean game
	./trabalhocg
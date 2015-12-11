SDLLIB = -L/usr/local/lib -lSDL2
SDLINC = -I/usr/local/include
COMPILER = gcc


all: sdl

debug: main.o world.o list.o player.o
	$(COMPILER) $^ -g -o $@ $(SDLLIB)

sdl: main.o world.o list.o player.o
	$(COMPILER) $^ -o $@ $(SDLLIB)
main.o: main.c
	$(COMPILER) $< -c $(SDLINC)

world.o: world.c
	$(COMPILER) $^ -c $(SDLINC)

list.o: list.c
	$(COMPILER) -c $<

player.o: player.c
	$(COMPILER) -c $< $(SDLINC)

clean:
	rm -f *~ main.o sdl list.o debug world.o player.o

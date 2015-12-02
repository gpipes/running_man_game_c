SDLLIB = -L/usr/local/lib -lSDL2
SDLINC = -I/usr/local/include
COMPILER = gcc


all: sdl

sdl: main.o
	$(COMPILER) $< -o $@ $(SDLLIB)
main.o: main.c
	$(COMPILER) $< -c $(SDLINC)
clean:
	rm -f *~ main.o sdl

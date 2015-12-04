SDLLIB = -L/usr/local/lib -lSDL2
SDLINC = -I/usr/local/include
COMPILER = gcc


all: sdl

sdl: main.o list.o
	$(COMPILER) $< -o $@ $(SDLLIB)
main.o: main.c
	$(COMPILER) $< -c $(SDLINC)

list_tests: list_tests.o list.o
	$(COMPILER) $^ -o $@
list_tests.o: list_tests.c
	$(COMPILER) -c $< -o $@ 

list.o: list.c
	$(COMPILER) $< -c


clean:
	rm -f *~ main.o sdl list.o list_tests list_tests.o

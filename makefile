cc = gcc
obj = src/sdl_fonctions.o src/main.o
flags = -lSDL2 -lSDL2_image

app: $(obj)
	gcc $(obj) -o app $(flags)

src/main.o: src/main.c include/sdl_fonctions.h
src/sdl_fonctions.o: src/sdl_fonctions.c include/sdl_fonctions.h

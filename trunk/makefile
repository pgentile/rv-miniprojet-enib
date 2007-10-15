# Variables
CC=g++
INCLUDES=-I./include
CC_FLAGS=-W -pedantic -ansi $(INCLUDES)
LD_FLAGS=-L/usr/X11R6/lib -L./lib -lGL -lGLU -lglut -ljpeg -lX11 -lXmu -lXi -lm -lpng
APPS=enib test
O_FILES=png-loader.o scene.o scene-composite.o scene-element.o transformation.o window.o

# Quelques notes :
#   - $@ : nom de la cible
#   - $< : la premiere dependance
#   - $^ : toutes les dependances

# Toutes les cibles
all: $(APPS)

# Notre application enib
enib: enib.o
	$(CC) -o $@ $^ $(LD_FLAGS)

# Notre application de test
test: test.o test-window.o test-scene.o barney.o $(O_FILES)
	$(CC) -o $@ $^ $(LD_FLAGS)

# Regle generique
%.o: src/%.cpp include/%.h
	$(CC) -c -o $@ $< $(CC_FLAGS)

# Regle generique pour les .h inexistants
include/%.h:
	@echo "$@ n'existe pas, mais tout baigne !"

# Nettoyage
clean:
	rm -f $(APPS)
	rm -f *.o
	rm -rf *~

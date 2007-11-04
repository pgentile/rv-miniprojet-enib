# Variables
CC=g++
INCLUDES=-I./include
CC_FLAGS=-W -pedantic -ansi $(INCLUDES)
LD_FLAGS=-L/usr/X11R6/lib -L./lib -lGL -lGLU -lglut -lX11 -lXmu -lXi -lm -lpng
APPS=enib
O_FILES=png-loader.o vertex.o vector.o size.o color.o transformation.o translation.o \
	rotation.o scale.o element.o composite-element.o window.o scene.o text-enter.o \
	text-parking.o

# Quelques notes :
#   - $@ : nom de la cible
#   - $< : la premiere dependance
#   - $^ : toutes les dependances

# Toutes les cibles
all: $(APPS)

# Notre application enib
enib: $(O_FILES) enib.o textured-rectangle.o depth-test-context.o alpha-test-context.o \
	tree.o soucoupe.o soucoupe-new-model.o soucoupe-cockpit.o positioned-element.o \
	soucoupe-light-sphere.o lighting-context.o landing-animation.o blending-context.o smoke-generator.o smoke.o lighting-context.o \
	text-enter.o text-parking.o
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
	rm -rf src/*~
	rm -rf include/*~


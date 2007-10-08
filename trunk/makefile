# Variables
CC=g++
INCLUDES=-I./include
CC_FLAGS=-W -pedantic -ansi $(INCLUDES)
LD_FLAGS=-L/usr/X11R6/lib -lGL -lGLU -lglut -ljpeg -lX11 -lXmu -lXi -lm
APPS=enib

# Quelques notes :
#   - $@ : nom de la cible
#   - $< : la premiere dependance
#   - $^ : toutes les dependances

# Toutes les cibles
all: $(APPS)

# Notre application enib
enib: src/enib.cpp abstract-window.o 
	$(CC) -o $@ $^ $(LD_FLAGS)

# Regle generique
%.o: src/%.cpp include/%.h
	$(CC) -c -o $@ $< $(CC_FLAGS)

# Nettoyage
clean:
	rm -f $(APPS)
	rm -f *.o
	rm -rf *~

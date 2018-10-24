# Makefile de chevres
# à faire :
#	- qu'il se démerde pour trouver toutes les sources dans le répertoire et sous-repertoires src

CC = g++
CXXFLAGS = -W -Wall -ansi -pedantic -std=c++11 #-static
# Les différents FrameWorks et bibliothèques pour le linkage
GLLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS =
SRCDIR = src
HEADDIR = src
OBJDIR = obj
BINDIR = bin
EXEC = chevres

SRC  = $(wildcard $(SRCDIR)/*.cpp)
SRC += $(wildcard $(SRCDIR)/Interface/*.cpp)
SRC += $(wildcard $(SRCDIR)/Simulation/*.cpp)
OBJ  = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

default : all

# all : liste les executables à produire
all : $(EXEC)

# Cible de construction de l'exécutable
$(EXEC): $(OBJ)
	@ [ -d $(BINDIR) ] || mkdir $(BINDIR)
	@ $(CC) -o $(BINDIR)/$@ $^ $(LDFLAGS) $(GLLIBS)
	@ [ -h $@ ] || ln -s $(BINDIR)/$@ $@

# Déclaration de a règle générique
# Si tous vos fichiers c/cpp n'ont pas de .h correspondant,
# vous pouvez enlever $(SRCDIR)/%.h des dépendances.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	@ [ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	@ $(CC) -o $@ -c $< $(CXXFLAGS) $(GLLIBS)

# commandes

# Nettoyage du répertoire des objets
clean:
	@ echo rm -f $(OBJDIR)/*.o
	@ rm -f $(OBJDIR)/*.o

# Suppression des répertoires des objets et des binaires
Clean: clean
	@ echo rm -rf $(EXEC) $(OBJDIR) $(BINDIR)
	@ rm -rf $(EXEC) $(OBJDIR) $(BINDIR)

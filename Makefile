CFLAGS = -g -O2 -Wall -Werror `pkg-config --cflags MLV`
LDLIBS = `pkg-config --libs MLV`
Snake: plateau.o affichage.o serpent.o pomme.o main.o
	gcc  -o Snake plateau.o affichage.o serpent.o pomme.o main.o  $(CFLAGS) $(LDLIBS)
pomme.o: pomme.c pomme.h serpent.h
	gcc -c pomme.c $(CFLAGS) $(LDLIBS)
plateau.o: plateau.c plateau.h pomme.h serpent.h son.c
	gcc -c plateau.c $(CFLAGS)
affichage.o: affichage.c affichage.h plateau.c
	gcc -c affichage.c $(CFLAGS) $(LDLIBS)
serpent.o: serpent.c serpent.h 
	gcc -c serpent.c $(CFLAGS)
son.o: son.c son.h 
	gcc -c serpent.c $(CFLAGS) $(LDLIBS)
main.o: main.c plateau.h serpent.h affichage.h pomme.h
	gcc -c main.c $(CFLAGS)

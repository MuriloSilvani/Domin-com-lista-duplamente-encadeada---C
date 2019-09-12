CPP    = g++
RM     = rm -f
OBJS   = main.o \
         domino.o

LIBS   =
CFLAGS =

.PHONY: Domino\ V4.exe clean clean-after

all: Domino\ V4.exe

clean:
	$(RM) $(OBJS) Domino\ V4.exe

clean-after:
	$(RM) $(OBJS)

Domino\ V4.exe: $(OBJS)
	$(CPP) -Wall -s -o '$@' $(OBJS) $(LIBS)

main.o: main.c domino.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

domino.o: domino.c domino.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)


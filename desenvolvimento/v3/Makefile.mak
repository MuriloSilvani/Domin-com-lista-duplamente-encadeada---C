CPP    = g++
RM     = rm -f
OBJS   = main.o \
         NovoArquivo.o

LIBS   =
CFLAGS =

.PHONY: Domino\ V3.exe clean clean-after

all: Domino\ V3.exe

clean:
	$(RM) $(OBJS) Domino\ V3.exe

clean-after:
	$(RM) $(OBJS)

Domino\ V3.exe: $(OBJS)
	$(CPP) -Wall -s -o '$@' $(OBJS) $(LIBS)

main.o: main.c
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

NovoArquivo.o: NovoArquivo.c
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)


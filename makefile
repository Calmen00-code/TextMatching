CC = gcc
CFLAGS = -Werror -Wall -pedantic -ansi -g
OBJA = main.o display.o colour.o ucp_string.o
OBJB = main.o displayIndex.o colour.o ucp_string.o
EXECA = text
EXECB = textIndex

all : $(EXECA) $(EXECB)

$(EXECA) : $(OBJA) 
	$(CC) $(OBJA) -o $(EXECA)

main.o : main.c display.h ucp_string.h
	$(CC) $(CFLAGS) -c main.c

display.o : display.c display.h ucp_string.h
	$(CC) $(CFLAGS) -c display.c

colour.o : colour.c colour.h display.h
	$(CC) $(CFLAGS) -c colour.c

ucp_string.o : ucp_string.c ucp_string.h display.h colour.h
	$(CC) $(CFLAGS) -c ucp_string.c

$(EXECB) : $(OBJB) 
	$(CC) $(OBJB) -o $(EXECB)

displayIndex.o : display.c display.h
	$(CC) -c display.c $(CFLAGS) -o displayIndex.o -D INDEX

clean:
	rm -f $(OBJA) $(EXECA) $(OBJB) $(EXECB) 

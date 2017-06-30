CC = gcc

CFLAGS = -Iheaders -g -Wall -Wextra -Werror -pedantic -march=native -std=c99

RM = rm -f

VPATH = src

OBJS = main.o

MAIN = tp3

$(MAIN): $(OBJS)
	@echo ""
	@echo " --- COMPILANDO PROGRAMA ---"
	@$(CC) $(CFLAGS) $(OBJS) -o $(MAIN)
	@echo ""

%.o: %.c %.h
	@echo " --- COMPILANDO OBJETO \"$@\""
	@$(CC) $(CFLAGS) $< -c

clean:
	$(RM) *.o *.gch

run: $(MAIN)
	./$(MAIN)

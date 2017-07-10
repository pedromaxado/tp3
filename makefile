CC = gcc

CFLAGS = -Iheaders -g -Wall -Wextra -Werror -pedantic -O2 -flto -std=c99

RM = rm -f

VPATH = src

OBJS = main.o pair.o vector.o gohorse.o greedy.o dp.o

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

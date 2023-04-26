CC = gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)
headers = $(wildcard *.h)

bin = hsh

CFLAGS = -I . -Wall -Wextra -Werror -pedantic -std=c99 -g

.PHONY: all clean fclean re

all: $(bin)

$(bin): $(obj) $(headers)
	$(CC) -o $@ $(obj) $(CFLAGS)

%.o: %.c $(headers)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(bin)

re: fclean all

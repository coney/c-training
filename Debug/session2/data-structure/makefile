SRC=$(wildcard *.c)
TARGETS=$(SRC:.c=)

% : %.c
	gcc -m32 -std=c99 -g -O0  $< -o $@

all : $(TARGETS)

clean:
	rm -rfv $(TARGETS)

.PHONY: all clean

TARGET=thread-debug

$(TARGET): *.c
	gcc -m32 -std=c99 -O0 -g  -pthread -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

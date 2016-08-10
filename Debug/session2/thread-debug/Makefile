TARGET=thread-debug

$(TARGET): *.c
	gcc -m32 -O0 -g  -pthread -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

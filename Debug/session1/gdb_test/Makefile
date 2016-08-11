TARGET=testapp

$(TARGET): *.c
	gcc -m32 -std=c99 -O0 -g -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

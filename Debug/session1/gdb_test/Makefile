TARGET=testapp

$(TARGET): *.c
	gcc -m32 -O0 -g -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

TARGET=testapp

$(TARGET): *.c
	gcc -O0 -g -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

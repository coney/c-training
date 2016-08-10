TARGET=thread-debug

$(TARGET): *.cpp
	g++ -O0 -g  -pthread -o $@ $<

all: $(TARGET)

clean:
	rm $(TARGET) -f

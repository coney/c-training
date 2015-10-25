TARGET=parking-lot
CPPFLAGS=-Ilib --std=gnu++0x -Wno-return-type


all: $(TARGET)
	./$(TARGET)

clean:
	rm -fv *.a *.o $(TARGET)

libgmock.a: lib/*.cc
	g++ $(CPPFLAGS) -c lib/*.cc
	ar rcs $@ gmock*.o

$(TARGET): *.cpp *.h libgmock.a
	g++ $(CPPFLAGS) libgmock.a -o $@ *.cpp

.PHONY: all clean

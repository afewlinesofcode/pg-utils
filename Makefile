# TODO: Don't have time for autotools at this moment. Will use them later.

TARGET=pg-util
CXXFLAGS=-std=c++14 -Iinclude
LDFLAGS=
HDRS=$(shell find include/ -type f -name '*.h')
SRCS=$(shell find src/ -type f -name '*.cpp')
OBJS=$(SRCS:.cpp=.o)

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ -o $@ $(OBJS)

%.o: %.cpp
	g++ -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

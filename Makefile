CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -pedantic

TARGET := examheap
SOURCES := examheap.cpp heap.cpp
HEADERS := heap.h

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

test: $(TARGET)
	@for test in 1 2 3 4 5 6 7; do ./$(TARGET) $$test || exit $$?; done

clean:
	rm -f $(TARGET)

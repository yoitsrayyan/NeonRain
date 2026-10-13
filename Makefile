CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -pedantic

TARGET := neonrain
SOURCE := src/NeonRainEffect.cpp
PREFIX ?= /usr/local

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) "$(DESTDIR)$(PREFIX)/bin/$(TARGET)"

uninstall:
	rm -f "$(DESTDIR)$(PREFIX)/bin/$(TARGET)"

clean:
	rm -f $(TARGET)

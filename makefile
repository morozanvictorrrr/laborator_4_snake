# setarile de compilator
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# fisierele sursa si obiective
SOURCES = main.cpp point.cpp apple.cpp board.cpp direction.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = SnakeGame

# Compilare principalaa
all: $(TARGET)

# legare obiecte si crearea executabilului
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# regula de compilare pentru fisierele .cpp în .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

# regulla pentru curatare
clean:
	rm -f $(OBJECTS) $(TARGET)

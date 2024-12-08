# Variables
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
TARGET = compute
SOURCES = main.cpp

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean rule to remove the compiled files
clean:
	rm -f $(TARGET)


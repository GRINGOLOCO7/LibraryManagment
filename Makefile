# Makefile for our simple project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# The target executable
TARGET = my_library_manager

# Source files
SRCS = src/library_manager_system2.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target, build the program
all: $(TARGET)

# Rule to link object files and create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to prevent conflicts with files named "all" or "clean"
.PHONY: all clean


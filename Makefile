# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -pthread

# Debugging flags
DEBUG_FLAGS = -g

# Directories
SRC_DIR = .
ANALISADOR_LEXICO_DIR = analisador_lexico
FNS_TRANSICAO_DIR = $(ANALISADOR_LEXICO_DIR)/funcoes_de_transicao
DEFS_FNS_TRANSICAO_DIR = $(FNS_TRANSICAO_DIR)/definicoes
TRANSICAO_DIR = $(ANALISADOR_LEXICO_DIR)/transicao

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cc) \
       $(wildcard $(ANALISADOR_LEXICO_DIR)/*.cc) \
       $(wildcard $(FNS_TRANSICAO_DIR)/*.cc) \
       $(wildcard $(TRANSICAO_DIR)/*.cc) \
       $(wildcard $(DEFS_FNS_TRANSICAO_DIR)/*.cc)

# Object files
OBJS = $(SRCS:.cc=.o)

# Executable name
TARGET = main

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(ANALISADOR_LEXICO_DIR) -I$(FNS_TRANSICAO_DIR) -I$(TRANSICAO_DIR) -I$(DEFS_FNS_TRANSICAO_DIR)

# Debugging mode
DEBUG = 0

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Compiling
%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(if $(DEBUG),$(DEBUG_FLAGS)) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

# Run with Valgrind
valgrind: $(TARGET)
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

# Set debugging option
debug:
	$(MAKE) DEBUG=1

.PHONY: all clean valgrind debug

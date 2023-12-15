# api/Makefile

# Set the installation prefix to /opt/ and the base name of the current directory
PREFIX ?= /opt/$(shell basename $(realpath .))

# Define the installation paths
INSTALL_DIR = $(DESTDIR)$(PREFIX)
BIN_DIR = $(INSTALL_DIR)/bin
LIB_DIR = $(INSTALL_DIR)/lib

# Specify the targets
.PHONY: all install

# List of object files specific to the "api" directory
API_OBJECTS = api_handler.o main.o

# Main executable for the "api" directory
API_EXECUTABLE = $(BIN_DIR)/api/my_civetweb_program

# Include paths
INCLUDE_DIRS = -I../CivetWebSourceCode/include

# Compiler flags
CXXFLAGS = -std=c++11 $(INCLUDE_DIRS)

all: $(API_EXECUTABLE)

$(API_EXECUTABLE): $(API_OBJECTS)
	@echo "Linking executable $@"
	@mkdir -p $(BIN_DIR)/api
	$(CXX) $(LDFLAGS) -o $@ $^

# Rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

install: all
	@echo "Installing to $(INSTALL_DIR)"
	install -d $(BIN_DIR)/api
	install -m 755 $(API_EXECUTABLE) $(BIN_DIR)/api

clean:
	@echo "Cleaning up"
	rm -f $(API_OBJECTS) $(API_EXECUTABLE)

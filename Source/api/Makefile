# Set the installation prefix to /opt/ and the base name of the current directory
PREFIX ?= /opt/$(shell basename $(realpath .))

# Define the installation paths
INSTALL_DIR = $(DESTDIR)$(PREFIX)
BIN_DIR = $(INSTALL_DIR)/bin
LIB_DIR = $(INSTALL_DIR)/lib

# Specify the targets
.PHONY: all install clean

# List of object files
OBJECTS = api/api_handler.o api/main.o civetweb-1.16/out/src/CivetServer.o civetweb-1.16/out/src/main.o civetweb-1.16/out/src/civetweb.o

# Main executable
EXECUTABLE = $(BIN_DIR)/my_civetweb_program

# Shared library
SHARED_LIBRARY = $(LIB_DIR)/libcivetweb.so

# Include paths
INCLUDE_DIRS = -I../CivetWebSourceCode/include

# Compiler flags
CXXFLAGS = -std=c++11 $(INCLUDE_DIRS)

all: $(EXECUTABLE) $(SHARED_LIBRARY)
    @echo "Build completed. Use 'make install' to install."

$(EXECUTABLE): $(OBJECTS)
    @echo "Linking executable $@"
    @mkdir -p $(BIN_DIR)
    $(CXX) $(LDFLAGS) -o $@ $^

$(SHARED_LIBRARY): $(OBJECTS)
    @echo "Linking shared library $@"
    @mkdir -p $(LIB_DIR)
    $(CXX) $(LDFLAGS) -shared -o $@ $^

# Rule for compiling source files
%.o: %.cpp
    @echo "Compiling $<"
    $(CXX) $(CXXFLAGS) -c -o $@ $<

install: all
    @echo "Installing to $(INSTALL_DIR)"
    install -d $(BIN_DIR)
    install -m 755 $(EXECUTABLE) $(BIN_DIR)
    install -d $(LIB_DIR)
    install -m 755 $(SHARED_LIBRARY) $(LIB_DIR)

clean:
    @echo "Cleaning up"
    rm -f $(OBJECTS) $(EXECUTABLE) $(SHARED_LIBRARY)

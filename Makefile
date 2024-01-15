.PHONY: all client server clean

all: client server

client:
	$(MAKE) -C src/client

server:
	$(MAKE) -C src/server

clean:
	$(MAKE) -C src/client clean
	$(MAKE) -C src/server clean

all:
	@mkdir -p bin
	@g++ src/hellobrowser.cpp -o bin/hellobrowser -lmicrohttpd

clean:
	rm -rf bin


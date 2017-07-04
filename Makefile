all:
	@mkdir -p bin
	@g++ src/hellobrowser.cpp -o bin/hellobrowser -lboost_system -pthread

clean:
	rm -rf bin


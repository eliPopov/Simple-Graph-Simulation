all: bin/cTrace

bin/cTrace: bin/main.o bin/Session.o bin/Graph.o bin/Tree.o bin/RootTree.o bin/MaxRankTree.o bin/CycleTree.o bin/ContactTracer.o bin/Virus.o
	@echo 'linking'
	g++ -o bin/cTrace bin/main.o bin/Session.o bin/Graph.o bin/Tree.o bin/ContactTracer.o bin/Virus.o bin/RootTree.o bin/MaxRankTree.o bin/CycleTree.o
#compilation:
bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Session.o: src/Session.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp

bin/Graph.o: src/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/Tree.o: src/Tree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp

bin/RootTree.o: src/RootTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RootTree.o src/RootTree.cpp

bin/MaxRankTree.o: src/MaxRankTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MaxRankTree.o src/MaxRankTree.cpp

bin/CycleTree.o: src/CycleTree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CycleTree.o src/CycleTree.cpp

bin/ContactTracer.o: src/ContactTracer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ContactTracer.o src/ContactTracer.cpp

bin/Virus.o: src/Virus.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Virus.o src/Virus.cpp

clean:
	@echo 'Cleaning'
	rm -f bin/*

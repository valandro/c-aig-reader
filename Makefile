INC = -I ./libs/
LIBS = libs/
SRC = src/
build: main.o aagReader.o aig.o
			g++ -o main main.o aagReader.o aig.o

main.o: $(SRC)main.cpp $(LIBS)aagReader.h 
		g++ $(INC) -c $(SRC)main.cpp

aagReader.o: $(SRC)aagReader.cpp $(LIBS)aagReader.h
		g++ $(INC) -c $(SRC)aagReader.cpp

aig.o: $(SRC)aig.cpp $(LIBS)aig.h 
		g++ $(INC) -c $(SRC)aig.cpp

clean: 
		rm aig.o aagReader.o main.o main
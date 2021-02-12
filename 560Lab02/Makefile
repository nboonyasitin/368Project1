L.2: main.o Driver.o
	g++ -std=c++11 -g -Wall main.o Driver.o -o L.2

main.o: main.cpp Driver.h 
	g++ -std=c++11 -g -Wall -c main.cpp 

Driver.o: Driver.h Driver.cpp
	g++ -std=c++11 -g -Wall -c Driver.cpp

# Hash.o: Hash.h Hash.cpp
# 	g++ -std=c++11 -g -Wall -c Hash.cpp

# LinkedList.o: LinkedList.h LinkedList.cpp Node.h
# 	g++ -std=c++11 -g -Wall -c LinkedList.cpp  

# Node.o: Node.h Node.cpp
# 	g++ -std=c++11 -g -Wall -c Node.cpp

clean: 
	rm *.o L.2
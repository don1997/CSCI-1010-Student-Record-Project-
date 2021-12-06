output: main.o includes/functions.o includes/menuAndFormat.o includes/stats.o
	g++ main.o includes/functions.o includes/menuAndFormat.o includes/stats.o -o output
	
main.o: main.cpp
	g++ -c main.cpp

functions.o: includes/functions.cpp includes/functions.h
	g++ -c includes/functions.cpp
	
menuAndFormat.o: includes/menuAndFormat.cpp includes/menuAndFormat.h
	g++ -c includes/menuAndFormat.cpp
stats.o: includes/stats.cpp includes/stats.h
	g++ -c includes/stats.cpp
clean: 
	rm *.o output

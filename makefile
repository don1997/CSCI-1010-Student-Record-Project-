output: main.o includes/functions.o includes/menuAndFormat.o
	g++ main.o includes/functions.o includes/menuAndFormat.o -o output
	
main.o: main.cpp
	g++ -c main.cpp

functions.o: includes/functions.cpp includes/functions.h
	g++ -c includes/functions.cpp
	
menuAndFormat.o: includes/menuAndFormat.cpp includes/menuAndFormat.h
	g++ -c includes/menuAndFormat.cpp

clean: 
	rm *.o output

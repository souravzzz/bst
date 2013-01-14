all: demo

demo: demo.o tree.o 
	g++ -g demo.o tree.o -o demo

demo.o: demo.cpp
	g++ -g -c demo.cpp

tree.o: tree.cpp
	g++ -g -c tree.cpp

clean:
	rm -rf *.o demo

main: main.o carta.o deck.o paciencia.o pilha.o
	g++ -o main main.o carta.o deck.o paciencia.o pilha.o

main.o: main.cpp paciencia.hpp
	g++ -c -o main.o main.cpp

carta.o: carta.cpp carta.hpp
	g++ -c -o carta.o carta.cpp

deck.o: deck.cpp deck.hpp
	g++ -c -o deck.o deck.cpp

paciencia.o: paciencia.cpp paciencia.hpp
	g++ -c -o paciencia.o paciencia.cpp

pilha.o: pilha.cpp pilha.hpp
	g++ -c -o pilha.o pilha.cpp

clean: 
	rm -f main *.o

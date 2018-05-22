prog: absGraph.o autoGraph.o Bfs.o cityGraph.o Dfs.o Dijkstra.o Edge.o Graph.o helpFunc.o main.o roadE.o Vertice.o
	g++ absGraph.o autoGraph.o Bfs.o cityGraph.o Dfs.o Dijkstra.o Edge.o Graph.o helpFunc.o main.o roadE.o Vertice.o -o ProgramGraph

absGraph.o: absGraph.cpp absGraph.h Vertice.h Edge.h
	g++ -c absGraph.cpp 

autoGraph.o: autoGraph.cpp autoGraph.h absGraph.h Vertice.h Edge.h
	g++ -c autoGraph.cpp 

Bfs.o: Bfs.cpp Bfs.h absGraph.h Vertice.h Edge.h Graph.h cityGraph.h roadE.h helpFunc.h autoGraph.h Exceptions.h
	g++ -c Bfs.cpp 

cityGraph.o: cityGraph.cpp cityGraph.h roadE.h Edge.h Vertice.h absGraph.h
	g++ -c cityGraph.cpp 

Dfs.o: Dfs.cpp Dfs.h absGraph.h Vertice.h Edge.h helpFunc.h Graph.h autoGraph.h Exceptions.h cityGraph.h roadE.h
	g++ -c Dfs.cpp 

Dijkstra.o: Dijkstra.cpp Dijkstra.h absGraph.h Vertice.h Edge.h Graph.h cityGraph.h roadE.h helpFunc.h autoGraph.h Exceptions.h
	g++ -c Dijkstra.cpp 

Edge.o: Edge.cpp Edge.h Vertice.h
	g++ -c Edge.cpp 

Graph.o: Graph.cpp Graph.h Edge.h Vertice.h absGraph.h
	g++ -c Graph.cpp 

helpFunc.o: helpFunc.cpp helpFunc.h Graph.h Edge.h Vertice.h absGraph.h autoGraph.h Exceptions.h cityGraph.h roadE.h
	g++ -c helpFunc.cpp 

main.o: main.cpp Graph.h Edge.h Vertice.h absGraph.h cityGraph.h roadE.h Dfs.h helpFunc.h autoGraph.h Exceptions.h Dijkstra.h Bfs.h
	g++ -c main.cpp 

roadE.o: roadE.cpp roadE.h Edge.h Vertice.h
	g++ -c roadE.cpp 

Vertice.o: Vertice.cpp Vertice.h
	g++ -c Vertice.cpp 

clean:
	rm *.o

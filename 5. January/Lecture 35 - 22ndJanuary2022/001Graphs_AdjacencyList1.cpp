/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<list>

using namespace std;

class graph {

	list<int>* l;
	int V;
	bool directed;

	public :

		graph(int V, bool directed=false) {
			this->V = V;
			l = new list<int>[V];
			this->directed = directed;

		}

		void addEdge(int u, int v) {
			l[u].push_back(v);
			if(!directed) {
				l[v].push_back(u);
			}
		}

		void print() {
			for(int i=0; i<V; i++) {
				cout << i << " : ";
				list<int> neighbourList = l[i];
				for(auto neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int main() {

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();

	return 0;
}
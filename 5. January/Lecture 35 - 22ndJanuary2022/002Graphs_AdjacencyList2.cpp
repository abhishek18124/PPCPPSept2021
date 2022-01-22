/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool directed;

	public :

		graph(bool directed=false) {
			this->directed = directed;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!directed) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int main() {


	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'D');
	g.addEdge('C', 'E');
	g.addEdge('D', 'E');

	g.print();

	return 0;
}
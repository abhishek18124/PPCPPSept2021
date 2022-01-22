/*

Implementation of the weighted graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class graph {
	map<T, list<pair<T, int>>> neighbourMap;
	bool directed;

	public :

		graph(bool directed=false) {
			this->directed = directed;
		}

		void addEdge(T u, T v, int w) {
			neighbourMap[u].push_back({v, w});
			if(!directed) {
				neighbourMap[v].push_back({u, w});
			}

			// neighbourMap[u].push_back(make_pair(v, w));
			// if(!directed) {
			// 	neighbourMap[v].push_back(make_pair(u, w));
			// }
		}

		void print() {
			for(pair<T, list<pair<T, int>>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<pair<T, int>> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					cout << "(" << neighbourLabel << ", " << edgeWeight << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int main() {


	graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 20);
	g.addEdge('B', 'C', 5);
	g.addEdge('B', 'D', 12);
	g.addEdge('C', 'D', 23);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 1);

	g.print();

	return 0;
}
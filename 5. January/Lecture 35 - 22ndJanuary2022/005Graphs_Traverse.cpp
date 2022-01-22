/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

*/

#include<iostream>
#include<map>
#include<unordered_set>
#include<list>
#include<queue>

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

		void bfs(T s, unordered_set<T>& visited) {
	
			queue<T> q;

			visited.insert(s);
			q.push(s);

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
					}
				}
			}

			cout << endl;

		}

		void traverse() {
			unordered_set<T> visited;
			int numComponents = 0;
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					cout << "bfs(" << vertexLabel << ") : ";
					bfs(vertexLabel, visited);
					numComponents++;
				}
			}

			cout << "I have found " << numComponents << " components!" << endl;
		}

};

int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.addEdge(9, 10);
	g.addEdge(10, 11);
	g.addEdge(11, 12);

	g.addEdge(13, 14);

	g.addEdge(15, 16);

	g.print();

	g.traverse();
		
	return 0;
}
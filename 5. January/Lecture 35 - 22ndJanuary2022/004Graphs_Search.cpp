/*
	
Implementation of graph search using

  1. depth first search   (dfs)
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

		void dfsHelper(T s, unordered_set<T>& visited) {
			cout << s << " ";
			visited.insert(s);

			list<T> neighbourList = neighbourMap[s];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					dfsHelper(neighbour, visited);
				}
 			}
		}

		void dfs(T s) {
			unordered_set<T> visited; // to keep track of vertices which are already visited
			cout << "dfs(" << s << ") : ";
			dfsHelper(s, visited);
			cout << endl;
		}

		void bfs(T s) {
			unordered_set<T> visited;
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

};

int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	// g.addEdge(0, 9);
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

	g.print();

	g.dfs(0);
	g.bfs(0);
	
	return 0;
}
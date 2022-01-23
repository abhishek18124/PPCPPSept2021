/*

Given an directed graph design an algorithm to check if there exists a back edge or not.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;

template <typename T>
class graph {
	unordered_map<T, list<T>> neighbourMap;

	public :

		void addEdge(T u, T v) {
			// insert a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		bool dfsHelper(T s, unordered_set<T>& visited, unordered_set<T>& stackState) {
			visited.insert(s);
			stackState.insert(s);
			list<T> neighbourList = neighbourMap[s];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					if(dfsHelper(neighbour, visited, stackState)) {
						return true;
					}
				} else {
					if(stackState.find(neighbour) != stackState.end()) {
						return true;
					}
				}
			}

			stackState.erase(s);
			return false;

		}

		bool isBackEdgePresent() {
			bool flag = false; // assume back edge is not present
			unordered_set<T> visited;
			unordered_set<T> stackState; // to keep track of vertices currently present on the func. call stack
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					if(dfsHelper(vertexLabel, visited, stackState)) {
						flag = true;
						break;
					}	
				}
			}

			return flag;
		}
};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('B', 'C');
	g.addEdge('C', 'D');
	// g.addEdge('D', 'A');

	g.isBackEdgePresent() ? cout << "BackEdge found!" << endl :
	                        cout << "BackEdge not found!" << endl;

	return 0;
}
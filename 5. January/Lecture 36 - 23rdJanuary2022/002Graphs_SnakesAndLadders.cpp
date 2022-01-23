/*

Snake and Ladders Game

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;

	public :

		void addEdge(T u, T v) {
			// insert a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		int bfs(T s, T d) {

			queue<T> q; 
			q.push(s);

			unordered_set<T> visited;
			visited.insert(s);
			
			map<T, int> distanceMap;
			distanceMap[s] = 0;

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
						distanceMap[neighbour] = 1 + distanceMap[front];
						parentMap[neighbour] = front;
					}
				}
			}

			T temp = d;
			while(parentMap[temp] != temp) {
				cout << temp << "<-";
				temp = parentMap[temp];
			}
			cout << temp << endl;

			return distanceMap[d];
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

int minDiceThrows(int n, vector<pair<int,int>> snakes, vector<pair<int,int>> ladders) {

	vector<int> weights(n+1, 0);

	for(auto snakePos : snakes) {
		int s = snakePos.first;
		int e = snakePos.second;
		weights[s] = e-s;
	}

	for(auto ladderPos : ladders) {
		int s = ladderPos.first;
		int e = ladderPos.second;
		weights[s] = e-s;
	}

	graph<int> g;

	for(int u=1; u<n; u++) {
		for(int d=1; d<=6 && u+d <= n; d++) {
			int v = u+d;
			v += weights[v];
			g.addEdge(u, v);
		}
	}

	return g.bfs(1, n);
	
}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {{17, 4}, 
									  {20, 6}, 
									  {24, 16}, 
									  {32, 30}, 
									  {34, 12}};

	vector<pair<int, int>> ladders = {{2, 15}, 
	                                  {5, 7}, 
	                                  {9, 27}, 
	                                  {18, 29}, 
	                                  {25, 35}};
	
	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}
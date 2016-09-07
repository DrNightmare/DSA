#include "iostream"
#include "vector"
#include "stack"
#include "queue"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

vector<int> adj[10];
bool visitedDFS[10];
bool visitedBFS[10];

// stack 1 2
// x 0
void dfs(int start) {
	stack<int> s;
	s.push(start);

	visitedDFS[start] = true;
	int x;

	while(!s.empty()) {
		x = s.top();
		cout << "Visited : " << x << '\n';
		s.pop();
		for(int i = 0; i < adj[x].size(); i++) {
			int neighbor = adj[x][i];
			if (!visitedDFS[neighbor]) {
				s.push(neighbor);
				visitedDFS[neighbor] = true;	
				// cout << "Visited : " << neighbor << '\n';
			}
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);

	visitedBFS[start] = true;
	int x;

	while(!q.empty()) {
		x = q.front();
		cout << "Visited : " << x << '\n';
		q.pop();
		for(int i = 0; i < adj[x].size(); i++) {
			int neighbor = adj[x][i];
			if (!visitedBFS[neighbor]) {
				q.push(neighbor);
				visitedBFS[neighbor] = true;	
				// cout << "Visited : " << neighbor << '\n';
			}
		}
	}
}

int main()
{
	int nodes, edges;
	int x, y;

	cin >> nodes >> edges;

	for(int i = 0; i < edges; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
	}	

	// for(int i = 0; i < nodes; i++) {
	// 	cout << "Adjacency list of node : " << i << '\n';
	// 	for(int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << ' ';
	// 	cout << '\n';
	// }

	cout << "DFS : \n";
	dfs(0);
	cout << "BFS : \n";
	bfs(0);
	return 0;
}
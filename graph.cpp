#include "iostream"
#include "vector"
#include "stack"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(int start) {
	stack<int> s;
	s.push(start);

	visited[start] = true;
	cout << "Visited : " << start << '\n';
	int x;

	while(!s.empty()) {
		x = s.top();
		s.pop();
		for(int i = 0; i < adj[x].size(); i++) {
			int neighbor = adj[x][i];
			if (!visited[neighbor]) {
				s.push(neighbor);
				visited[neighbor] = true;	
				cout << "Visited : " << neighbor << '\n';
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

	for(int i = 0; i < nodes; i++) {
		cout << "Adjacency list of node : " << i << '\n';
		for(int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << ' ';
		cout << '\n';
	}

	dfs(0);
	return 0;
}
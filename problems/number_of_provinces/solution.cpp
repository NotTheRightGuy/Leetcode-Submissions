class Solution {
public:
    vector<vector<int>> matToList(vector<vector<int>> isConnected) {
	int nodes = isConnected.size();
	vector<vector<int>> adj(nodes);
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (isConnected[i][j]) {
				adj[i].push_back(j);
			}
		}
	}
	return adj;
}

void bfs(vector<vector<int>> &adjList, vector<int> &visited, int root, int &province) {
	if (visited[root]) return;
	queue<int> q;
	q.push(root);
	visited[root] = 1;
	province++;
	while (!q.empty()) {
		int child = q.front();
		q.pop();
		for (auto it : adjList[child]) {
			if (!visited[it]) {
				q.push(it);
				visited[it] = 1;
			}
		}
	}
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			bfs(adjList, visited, i, province);
		}
	}
}

int findCircleNum(vector<vector<int>> &isConnected) {
	vector<vector<int>> adjList = matToList(isConnected);
	int province = 0;
	vector<int> visited(isConnected.size(), 0);
	bfs(adjList, visited, 0, province);
	return province;
}
};
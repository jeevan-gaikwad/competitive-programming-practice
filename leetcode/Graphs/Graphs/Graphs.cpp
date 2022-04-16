// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
//topo sort. This function assumes that provided graph is DAG
void DFS(int sVert, int V, vector<int> adj[], vector<int>& visited, stack<int>& topoSort) {

	visited[sVert] = 1;
	for (auto& node : adj[sVert]) {
		if (visited[node] == -1) { //check is adjacent node visited
			DFS(node, V, adj, visited, topoSort);
		}
	}
	//once done, we should put the curr node into the stack
	topoSort.push(sVert);
}
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int> sol;
	if (V == 0) {
		return sol;
	}
	vector<int> visited(V, -1);
	stack<int> topoSort;
	for (int i = 0; i < V; ++i) {
		if (visited[i] == -1) { //need to visit
			DFS(i, V, adj, visited, topoSort);
		}
	}
	while (topoSort.size() > 0) {
		sol.emplace_back(topoSort.top());
		topoSort.pop();
	}
	return sol;
}
//-----------topo sort using DFS ends------------

int main()
{
    std::cout << "Hello World!\n";
}


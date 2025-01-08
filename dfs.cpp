#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(int start_node,vector<vector<int>>&adj,vector<bool>&visited)
{
    cout<<endl;
    stack<int>s;
    s.push(start_node);
    visited[start_node] = true;
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        cout<<u<<endl;
        for(int neignbour:adj[u]) {
            if(!visited[neignbour]) {
                s.push(neignbour);
                visited[neignbour] = true;
        }
    }
}
}

bool dfs_path(int current, int target, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path) {
    visited[current] = true;
    path.push_back(current);

    cout << "Visiting node: " << current << endl; // Print visited node

    if (current == target) {
        return true;
    }

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (dfs_path(neighbor, target, adj, visited, path)) {
                return true;
            }
        }
    }

    path.pop_back(); 
    return false;
}

int main()
{
    int num_nodes,num_edges;
    cout<<"Enter the number of nodes and edges\n";
    cin>>num_nodes>>num_edges;
    vector<vector<int>>adj(num_nodes);
    cout<<"Enter the edges\n";
    for(int i=0;i<num_edges;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Enter the starging Node\n";
    int start_node;
    cin>>start_node;
    vector<bool>visited(num_nodes,false);
    int target;
    cout<<"Enter target Node\n";
    cin>>target;
    DFS(start_node,adj,visited);
    vector<int>path;
    visited.assign(num_nodes, false);
    cout << "\nPerforming DFS Search (with path reconstruction):\n";
    if (dfs_path(start_node,target,adj,visited, path)) {
        cout << "Path found: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;    

void BFS(int start_node , vector<vector<int>>& adj, vector<bool>& visited)
{
    queue<int>q;
    q.push(start_node);
    visited[start_node] = true;
    while(!q.empty()) {
        int cur_node = q.front();
        q.pop();

        cout<<cur_node<<endl;
        for(int neighbour : adj[cur_node]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
using namespace std;
int main()
{   
    int num_nodes , num_edges;
    cout<<" Enter the number of nodes and edges\n";
    cin>>num_nodes>>num_edges;
    vector<vector<int>>adj(num_nodes);
    cout<<"Enter the edges(u,v)\n";
    for(int i=0;i<num_edges;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(num_nodes,false);
    cout<<"Enter the starting node of the graph\n";
    int start_node;
    cin>>start_node;
    cout<<" The BFS travesral is \n";
    BFS(start_node,adj,visited);
    cout<<endl;
    
    cout<<"BFS traversal for the whole graph (handling disconnected graphs is )\n";
    visited.assign(num_nodes,false);
    for (size_t i = 0; i < num_nodes; i++)
    {
        if(!visited[i]) {
            BFS(i,adj,visited);
        }
    }
    cout<<endl;
    return 0;
}
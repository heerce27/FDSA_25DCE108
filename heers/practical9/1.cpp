#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
bool visited[100];
// Depth First Search
void DFS(int node) {
    visited[node] = true;
    cout<<node<<" ";
    for(int next : graph[node]) {
        if (!visited[next]){
            DFS(next);
        }
    }
}

// Breadth First Search
void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, e;
    cout<<"Enter number of buildings and roads: ";
    cin>>n>>e;
    cout<<"Enter roads (building1 building2):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout<<"Enter starting building: ";
    cin>>start;
    cout<<"DFS Order: ";
    DFS(start);
    for(int i = 0; i < 100; i++)
        visited[i] = false;
    cout<<"\nBFS Order: ";
    BFS(start);
    cout<<endl;
    return 0;
}
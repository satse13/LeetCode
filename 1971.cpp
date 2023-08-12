#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<bool> visited(n, false) ;
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adjList, visited, source, destination);

    }

    bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, int source, int destination){
        if(source == destination)
            return true;
        if(visited[source])
            return false;

        visited[source] = true;
        for (int i = 0; i < adjList[source].size();i++){
            if(dfs(adjList, visited, adjList[source][i], destination))
                return true;
        }
        return false;
    }

};

int main(){
    return 0;
}
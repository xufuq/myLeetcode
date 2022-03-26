#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

vector<vector<int>> result;

void getPath(vector<vector<int>>& graph, vector<int> &path, int currentNode, int n){
    path.push_back(currentNode);
    if(currentNode == n-1){
        result.push_back(path);
        path.pop_back();
        return;
    }
    for(auto nextNode : graph[currentNode]){
        getPath(graph, path, nextNode, n);
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    getPath(graph, path, 0, graph.size());
    return result;
}
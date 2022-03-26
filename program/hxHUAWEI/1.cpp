#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int getNodeSumValue(int root, vector<int> &nodeValue, vector<int> &NodeSum, vector<vector<int>> &rootLeaves) {
    int left=0, right=0;
    if(rootLeaves[root].size()>0) // 有左节点
        left=getNodeSumValue(rootLeaves[root][0], nodeValue, NodeSum, rootLeaves);
    if(rootLeaves[root].size()>1) // 有右节点
        right=getNodeSumValue(rootLeaves[root][1], nodeValue, NodeSum, rootLeaves);

    NodeSum[root] = left+right+nodeValue[root];
    return NodeSum[root];
}

int getMaxValue(int nodeNum, vector<int> &nodeValue, vector<vector<int>> &nodeLRleaves) {
    vector<vector<int>> rootLeaves(nodeNum);
    for(auto &leaves : nodeLRleaves) 
        rootLeaves[leaves[0]].push_back(leaves[1]);
    
    vector<int> NodeSum(nodeNum);
    getNodeSumValue(0, nodeValue, NodeSum, rootLeaves);
    int maxIndex=0, MaxValue=0;
    for(int i=1; i<nodeNum; i++){
        if(abs(NodeSum[0]-2*NodeSum[i])>MaxValue) {
            MaxValue=abs(NodeSum[0]-2*NodeSum[i]);
            maxIndex=i;
        }
    }
    return maxIndex;
}

int main(){
    int num, count=0;
    cin>>num;

    vector<int> nodeValue(num);
    vector<vector<int>> nodeLRleaves(num-1);
    
    while(count<num) 
        cin >> nodeValue[count++];
    vector<int> temp(2);
    // cin >> temp[0];
    count=0;
    for(int i=0; i<num-1; ++i) {
        cin >> temp[0];
        cin >> temp[1];
        cout << temp[0] << " " << temp[1] << endl;
        nodeLRleaves[i]=temp;
    }
    cout << getMaxValue(num, nodeValue, nodeLRleaves);
    return 0;
}
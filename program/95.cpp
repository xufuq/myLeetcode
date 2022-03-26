#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归，找到中间点，然后分左右两边，再按照相同方式求解
vector<TreeNode*> generateTrees(int sIndex, int eIndex) {
    vector<TreeNode*> result;
    if(sIndex==eIndex) {
        TreeNode *curNode=new TreeNode(sIndex);
        result.push_back(curNode);
        return result;
    }
    else if(sIndex<eIndex) { 
        // i=index
        for(int i=sIndex;i<=eIndex;++i) {
            vector<TreeNode*> Lres=generateTrees(sIndex, i-1);
            vector<TreeNode*> Rres=generateTrees(i+1, eIndex);
            if(Lres.empty()) {
                for(int k=0;k<Rres.size();++k) {
                    TreeNode *curNode=new TreeNode(i);
                    curNode->right=Rres[k];
                    result.push_back(curNode);
                }
            }
            else if(Rres.empty()) {
                for(int j=Lres.empty()?-1:0;j<Lres.size();++j) {
                    TreeNode *curNode=new TreeNode(i);
                    curNode->left=Lres[j];
                    result.push_back(curNode);
                }
            }
            else{
                for(int j=0;j<Lres.size();++j) {
                    for(int k=0;k<Rres.size();++k) {
                        TreeNode *curNode=new TreeNode(i);
                        curNode->left=Lres[j];
                        curNode->right=Rres[k];
                        result.push_back(curNode);
                    }
                }
            }
            
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    return generateTrees(1, n);
}
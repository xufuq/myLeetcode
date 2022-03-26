#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// 在arr的前k个元素的内存中维护一个大根堆

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        cout << arr.size() << " " << k << endl;
        if(arr.size()<k) return arr;
        count=0;
        for(auto &num : arr) {
            if(count<k){
                ++count;
                insert(arr);
            }
            else {
                if(num<arr[0]) {
                    swap(arr[0], num);
                    sink(arr);
                }
            }
        }
        return vector<int>(arr.begin(), arr.begin()+count);
    }

    void insert(vector<int>& arr){
        // root指的是节点数，在数组运算的时候需要减1，逐级向上
        int cur=count, root=cur/2;
        while(root>0 && arr[root-1]<arr[cur-1]){
            swap(arr[root-1], arr[cur-1]);
            cur=root, root=cur/2;
        }
    }

    void sink(vector<int>& arr) { // 怎么让当前元素变的符合大根堆的要求
        int cur=1;
        while(cur<=count/2){
            int childIndex;
            if(cur<count/2 || (cur==count/2 && count%2))
                childIndex= arr[2*cur-1]>arr[2*cur]? 2*cur:2*cur+1; /// 根节点和较大的子节点比较
            else
                childIndex= 2*cur;
            if(childIndex>count) break;
            if(arr[cur-1]<arr[childIndex-1]){
                swap(arr[cur-1], arr[childIndex-1]);
                cur=childIndex;
            } else break;
        }
    }

private:
    int count;
};

// 还有一个快排的方法是只划分左右范围，而不用具体的排序，递归实现即可

int main(){
    Solution solution;
    vector<int> arr= {62577,-220,-8737,-22,-6,59956,5363,-16699,0,-10603,64,-24528,-4818,96,5747,2638,-223,37663,-390,35778,-4977,-3834,-56074,7,-76,601,-1712,
    -48874,31,3,-9417,-33152,775,9396,60947,-1919,683,-37092,-524,-8,1458,80,-8,1,7,-355,9,397,-30,-21019,-565,8762,-4,531,-211,-23702,3,3399,-67,64542,39546,
    52500,-6263,4,-16,-1,861,5134,8,63701,40202,43349,-4283,-3,-22721,-6,42754,-726,118,51,539,790,-9972,41752,0,31,-23957,-714,-446,4,-61087,84,-140,6,53,-48496,
    9,-15357,402,5541,4,53936,6,3,37591,7,30,-7197,-26607,202,140,-4,-7410,2031,-715,4,-60981,365,-23620,-41,4,-2482,-59,5,-911,52,50068,38,61,664,0,-868,8681,-8,8,29,412};

    vector<int> result=solution.smallestK(arr, 131);
    for(auto r : result)
        cout << r << " ";
}
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize=capacity;
        curSize=0;
    }
    
    int get(int key) {
        auto it = myList.cbegin();
        while(it!=myList.cend()){
            if(it->first==key) {
                myList.push_back(*it);
                myList.erase(it);
                return myList.back().second;
            }
            else ++it;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = myList.begin();
        while(it!=myList.end()){
            if(it->first==key) {
                myList.erase(it);
                myList.push_back(pair<int,int>(key,value));
                return;
            }
            else ++it;
        }
        if(curSize<maxSize) {
            myList.push_back(pair<int, int>(key, value));
            ++curSize;
        }
        else{
            myList.erase(myList.begin());
            myList.push_back(pair<int, int>(key, value));
        }
    }
    int maxSize, curSize;
    list<pair<int, int>> myList;
};

// 使用map，那最久未使用应该怎么表示呢
// 利用一个哈希表和一个双向链表，哈希表的值对应存的是链表对应的节点

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev, *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize=capacity;
        head=new DLinkedNode;
        tail=new DLinkedNode;
        head->next=tail;
        tail->prev=head;
    }
    // 最新使用的放到尾，最不常用的放在头
    int get(int key) {
        if(dMap.count(key)){ // 存在
            DLinkedNode *node=dMap[key];
            removeNode(node);
            addToTail(node);
            return node->value;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(dMap.count(key)){ // 存在
            DLinkedNode *node=dMap[key];
            node->value=value;
            removeNode(node);
            addToTail(node);
        } else { // 不存在
            if(dMap.size()==maxSize){ // 查看大小限制
                dMap.erase(head->next->key);
                removeNode(head->next);
            }
            DLinkedNode *node=new DLinkedNode(key, value);
            dMap.insert(pair<int, DLinkedNode*>(key, node));
            addToTail(node);
        }
    }

private:
    // 把新节点添加到链表尾
    void addToTail(DLinkedNode *node){
        tail->prev->next=node;
        node->prev=tail->prev;
        tail->prev=node;
        node->next=tail;
    }
    // 移除刚使用的节点
    void removeNode(DLinkedNode *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    int maxSize;
    DLinkedNode *head=nullptr, *tail=nullptr;
    unordered_map<int, DLinkedNode*> dMap;
};
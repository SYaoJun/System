//
// Created by 姚军 on 2022/9/5.
//

#ifndef SERVER_SKIPLIST_H
#define SERVER_SKIPLIST_H
class Skiplist {
        struct Node{
            int val;
            Node* right, *down;
            Node(int v, Node* r, Node* d):val(v),right(r), down(d){}
        };
public:
    int level = 0;
    Node* head = nullptr;
    Skiplist() = default;
    bool get(int target);
    void put(int num);
    bool erase(int num);
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

#endif //SERVER_SKIPLIST_H

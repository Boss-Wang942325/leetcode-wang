/*
题目大意:
    给出一个多级双向链表,将其扁平化

方法1: 迭代
方法2: 递归

*/

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};



/*
方法1

大致思路:
    ·首先一个大循环遍历主链表, 每遇到一个子链表, 进入并将其合并
    ·此时主循环并不会跳过该子链表中是否还有子链表, 因为子链表永远在主循环的右边
    ·所以每次循环最多处理一个子链表, 后面的子链表不会漏

问题:
    1. 如何不破坏给出的链表

*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head;
        while (p != nullptr) {              //主循环, 遍历主链表
            if (p->child != nullptr) {
                Node* next = p->next;       //标记,防止丢失主链表
                Node* child = p->child;     //指向子链表, 用于遍历, 插入主链表, 并且此次循环只处理该子链表
                p->next = child;
                p->child = nullptr;
                child->prev = p;

                while (child->next != nullptr) child = child->next;     //遍历到子链表末项
                child->next = next;         //连接主链表
                if (next != nullptr) next->prev = child;
            }
            p = p->next;
        }
        return head;
    }
};



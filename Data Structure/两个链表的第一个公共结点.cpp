//***无需考虑输入输出问题***

// 输入两个链表，找出它们的第一个公共结点。
// 当不存在公共节点时，返回空节点。

// 数据范围
// 链表长度 [1,2000]。

// 样例
// 给出两个链表如下所示：
// A：        a1 → a2
//                   ↘
//                      c1 → c2 → c3
//                   ↗            
// B:     b1 → b2 → b3

// 输出第一个公共节点c1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode * p = headA, * q = headB;								//定义两个指针分别指向A、B链表的头部 
        while(p!=q)														//如果pq的地址不一样（迫使两个指针走全程） 
        {
            if(p) p = p->next;
            else p = headB;
            if(q) q = q->next;
            else q = headA;
        }
        return p;
    }
};

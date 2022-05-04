//***无需考虑输入输出问题***

// 在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留。

// 数据范围
// 链表中节点 val 值取值范围 [0,100]。
// 链表长度 [0,100]。

// 样例1
// 输入：1->2->3->3->4->4->5

// 输出：1->2->5
// 样例2
// 输入：1->1->1->2->3

// 输出：2->3

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
    ListNode* deleteDuplication(ListNode* head) {
        auto dummy = new ListNode(-1);								//设置 虚拟头节点 dummy 指向 动态创建的结构体 ListNode （初始化一个val等于-1的ListNode类型的对象） （指针为空） 
        dummy->next = head;											//让 dummy 指向头结点（如果头结点存在的话） 

        auto p = dummy;
        while (p->next) {											//如果头结点（下一个点）存在 
            auto q = p->next;										//创建指针 q 指向下一个结点 （购买哨兵） 
            while (q && p->next->val == q->val) q = q->next;		//如果下一个结点的值与当前结点的值相等 ，让q继续指下一个，直到不相等 （让哨兵去巡逻） 

            if (p->next->next == q) p = p->next;					//如果没有重复的结点， p 指向下一个结点 
            else p->next = q;										//如果有重复的结点， p 指向删除重复结点后的下一个结点 
        }

        return dummy->next;											//*******（此处不理解）如果head节点没有被删除的话指向head节点，被删除就指向下一个满足条件的点，例如[4, 4, 4],head节点不变，dummy指向NULL。
    }
};

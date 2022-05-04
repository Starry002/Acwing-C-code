//***无需考虑输入输出问题***

// 输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。

// 数据范围
// 链表长度 [0,500]。

// 样例
// 输入：1->3->5 , 2->4->5

// 输出：1->2->3->4->5->5
 
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);						//设置 头指针 dummy 指向 动态创建的结构体 ListNode 	
        ListNode *cur = dummy;									//设置 尾指针 cur 指向头指针 dummy 
        
        while (l1 != NULL && l2 != NULL) {						//循环以下步骤直到l1或l2为空。 
            if (l1 -> val < l2 -> val) {						//若 l1 指针指向的结点的值 val 比l2指针指向的结点的值 val 小 则令 cur 的 next 指针指向l1，且l1后移
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {												//若 l1 指针指向的结点的值 val 比l2指针指向的结点的值 val 大 则令 cur 的 next 指针指向l2，且l2后移 
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;									//将 cur 指针按照上一步设置好的位置后移 
        }
        
        cur -> next = (l1 != NULL ? l1 : l2);					//将剩余的 l1 或 l2 接到 cur 指针后边 
        return dummy -> next;									//*******（此处不理解）
    }
};



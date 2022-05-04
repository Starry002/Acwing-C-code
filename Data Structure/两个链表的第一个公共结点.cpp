//***���迼�������������***

// �������������ҳ����ǵĵ�һ��������㡣
// �������ڹ����ڵ�ʱ�����ؿսڵ㡣

// ���ݷ�Χ
// ������ [1,2000]��

// ����
// ������������������ʾ��
// A��        a1 �� a2
//                   �K
//                      c1 �� c2 �� c3
//                   �J            
// B:     b1 �� b2 �� b3

// �����һ�������ڵ�c1

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
        ListNode * p = headA, * q = headB;								//��������ָ��ֱ�ָ��A��B�����ͷ�� 
        while(p!=q)														//���pq�ĵ�ַ��һ������ʹ����ָ����ȫ�̣� 
        {
            if(p) p = p->next;
            else p = headB;
            if(q) q = q->next;
            else q = headA;
        }
        return p;
    }
};

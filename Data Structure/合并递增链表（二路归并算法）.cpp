//***���迼�������������***

// ����������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ��յ�������ġ�

// ���ݷ�Χ
// ������ [0,500]��

// ����
// ���룺1->3->5 , 2->4->5

// �����1->2->3->4->5->5
 
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
        ListNode *dummy = new ListNode(0);						//���� ͷָ�� dummy ָ�� ��̬�����Ľṹ�� ListNode 	
        ListNode *cur = dummy;									//���� βָ�� cur ָ��ͷָ�� dummy 
        
        while (l1 != NULL && l2 != NULL) {						//ѭ�����²���ֱ��l1��l2Ϊ�ա� 
            if (l1 -> val < l2 -> val) {						//�� l1 ָ��ָ��Ľ���ֵ val ��l2ָ��ָ��Ľ���ֵ val С ���� cur �� next ָ��ָ��l1����l1����
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {												//�� l1 ָ��ָ��Ľ���ֵ val ��l2ָ��ָ��Ľ���ֵ val �� ���� cur �� next ָ��ָ��l2����l2���� 
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;									//�� cur ָ�밴����һ�����úõ�λ�ú��� 
        }
        
        cur -> next = (l1 != NULL ? l1 : l2);					//��ʣ��� l1 �� l2 �ӵ� cur ָ���� 
        return dummy -> next;									//*******���˴�����⣩
    }
};



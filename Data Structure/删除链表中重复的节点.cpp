//***���迼�������������***

// ��һ������������У������ظ��Ľڵ㣬��ɾ�����������ظ��Ľڵ㣬�ظ��Ľڵ㲻������

// ���ݷ�Χ
// �����нڵ� val ֵȡֵ��Χ [0,100]��
// ������ [0,100]��

// ����1
// ���룺1->2->3->3->4->4->5

// �����1->2->5
// ����2
// ���룺1->1->1->2->3

// �����2->3

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
        auto dummy = new ListNode(-1);								//���� ����ͷ�ڵ� dummy ָ�� ��̬�����Ľṹ�� ListNode ����ʼ��һ��val����-1��ListNode���͵Ķ��� ��ָ��Ϊ�գ� 
        dummy->next = head;											//�� dummy ָ��ͷ��㣨���ͷ�����ڵĻ��� 

        auto p = dummy;
        while (p->next) {											//���ͷ��㣨��һ���㣩���� 
            auto q = p->next;										//����ָ�� q ָ����һ����� �������ڱ��� 
            while (q && p->next->val == q->val) q = q->next;		//�����һ������ֵ�뵱ǰ����ֵ��� ����q����ָ��һ����ֱ������� �����ڱ�ȥѲ�ߣ� 

            if (p->next->next == q) p = p->next;					//���û���ظ��Ľ�㣬 p ָ����һ����� 
            else p->next = q;										//������ظ��Ľ�㣬 p ָ��ɾ���ظ��������һ����� 
        }

        return dummy->next;											//*******���˴�����⣩���head�ڵ�û�б�ɾ���Ļ�ָ��head�ڵ㣬��ɾ����ָ����һ�����������ĵ㣬����[4, 4, 4],head�ڵ㲻�䣬dummyָ��NULL��
    }
};

//***���迼�������������***

// ����һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ��㡣

// ���ݷ�Χ
// ������ [0,30]��

// ����
// ����:1->2->3->4->5->NULL

// ���:5->4->3->2->1->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//�����汾
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;					//�����һ����ָ��          prev 
        ListNode *cur = head;						//����ڶ���ָ��ͷ����ָ��  cur 
        while (cur)
        {
            ListNode *next = cur->next;				//���� cur ����һ��λ�� next  
            cur->next = prev;						//�� cur ָ���һ��ָ�� prev 
            prev = cur;								//����һ��ָ�� prev �ĵ�ַ��Ϊ���ڵ�λ�� 
            cur = next;								//���ڶ���ָ�� cur �ĵ�ַ��Ϊ��һ��λ�� 
        }
        return prev;								//���ط�ת�������ͷ���
    }
};


//�ݹ�汾
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};


//LeetCodeժ������û����   -.- 

///**
//     * ������1->2->3->4->5����
//     * @param head
//     * @return
//     */
//    public ListNode reverseList(ListNode head) {
//        if (head == null || head.next == null) {
//            /*
//                ֱ����ǰ�ڵ����һ���ڵ�Ϊ��ʱ���ص�ǰ�ڵ�
//                ����5û����һ���ڵ��ˣ����Դ˴����ؽڵ�5
//             */
//            return head;
//        }
//        //�ݹ鴫����һ���ڵ㣬Ŀ����Ϊ�˵������һ���ڵ�
//        ListNode newHead = reverseList(head.next);
//                /*
//            ��һ�ֳ�ջ��headΪ5��head.nextΪ�գ�����5
//            �ڶ��ֳ�ջ��headΪ4��head.nextΪ5��ִ��head.next.next=headҲ����5.next=4��
//                      �ѵ�ǰ�ڵ���ӽڵ���ӽڵ�ָ��ǰ�ڵ�
//                      ��ʱ����Ϊ1->2->3->4<->5������4��5����ָ�����Դ˴�Ҫ�Ͽ�4.next=null
//                      ��ʱ����Ϊ1->2->3->4<-5
//                      ���ؽڵ�5
//            �����ֳ�ջ��headΪ3��head.nextΪ4��ִ��head.next.next=headҲ����4.next=3��
//                      ��ʱ����Ϊ1->2->3<->4<-5������3��4����ָ�����Դ˴�Ҫ�Ͽ�3.next=null
//                      ��ʱ����Ϊ1->2->3<-4<-5
//                      ���ؽڵ�5
//            �����ֳ�ջ��headΪ2��head.nextΪ3��ִ��head.next.next=headҲ����3.next=2��
//                      ��ʱ����Ϊ1->2<->3<-4<-5������2��3����ָ�����Դ˴�Ҫ�Ͽ�2.next=null
//                      ��ʱ����Ϊ1->2<-3<-4<-5
//                      ���ؽڵ�5
//            �����ֳ�ջ��headΪ1��head.nextΪ2��ִ��head.next.next=headҲ����2.next=1��
//                      ��ʱ����Ϊ1<->2<-3<-4<-5������1��2����ָ�����Դ˴�Ҫ�Ͽ�1.next=null
//                      ��ʱ����Ϊ1<-2<-3<-4<-5
//                      ���ؽڵ�5
//            ��ջ��ɣ�����ͷ�ڵ�5->4->3->2->1
//         */
//        head.next.next = head;
//        head.next = null;
//        return newHead;
//    }
// 

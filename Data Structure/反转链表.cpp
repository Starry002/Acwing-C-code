//***无需考虑输入输出问题***

// 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

// 数据范围
// 链表长度 [0,30]。

// 样例
// 输入:1->2->3->4->5->NULL

// 输出:5->4->3->2->1->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//迭代版本
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;					//定义第一个空指针          prev 
        ListNode *cur = head;						//定义第二个指向头部的指针  cur 
        while (cur)
        {
            ListNode *next = cur->next;				//储存 cur 的下一个位置 next  
            cur->next = prev;						//让 cur 指向第一个指针 prev 
            prev = cur;								//将第一个指针 prev 的地址改为现在的位置 
            cur = next;								//将第二个指针 cur 的地址改为下一个位置 
        }
        return prev;								//返回反转后链表的头结点
    }
};


//递归版本
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


//LeetCode摘抄，还没看嘞   -.- 

///**
//     * 以链表1->2->3->4->5举例
//     * @param head
//     * @return
//     */
//    public ListNode reverseList(ListNode head) {
//        if (head == null || head.next == null) {
//            /*
//                直到当前节点的下一个节点为空时返回当前节点
//                由于5没有下一个节点了，所以此处返回节点5
//             */
//            return head;
//        }
//        //递归传入下一个节点，目的是为了到达最后一个节点
//        ListNode newHead = reverseList(head.next);
//                /*
//            第一轮出栈，head为5，head.next为空，返回5
//            第二轮出栈，head为4，head.next为5，执行head.next.next=head也就是5.next=4，
//                      把当前节点的子节点的子节点指向当前节点
//                      此时链表为1->2->3->4<->5，由于4与5互相指向，所以此处要断开4.next=null
//                      此时链表为1->2->3->4<-5
//                      返回节点5
//            第三轮出栈，head为3，head.next为4，执行head.next.next=head也就是4.next=3，
//                      此时链表为1->2->3<->4<-5，由于3与4互相指向，所以此处要断开3.next=null
//                      此时链表为1->2->3<-4<-5
//                      返回节点5
//            第四轮出栈，head为2，head.next为3，执行head.next.next=head也就是3.next=2，
//                      此时链表为1->2<->3<-4<-5，由于2与3互相指向，所以此处要断开2.next=null
//                      此时链表为1->2<-3<-4<-5
//                      返回节点5
//            第五轮出栈，head为1，head.next为2，执行head.next.next=head也就是2.next=1，
//                      此时链表为1<->2<-3<-4<-5，由于1与2互相指向，所以此处要断开1.next=null
//                      此时链表为1<-2<-3<-4<-5
//                      返回节点5
//            出栈完成，最终头节点5->4->3->2->1
//         */
//        head.next.next = head;
//        head.next = null;
//        return newHead;
//    }
// 

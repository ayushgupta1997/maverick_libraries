/**
InterviewBit problem : https://www.interviewbit.com/problems/palindrome-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int findLen(ListNode* A) {
     int l = 0;
     ListNode* temp = A;
     while(temp!=NULL) {
         temp = temp->next;
         l++;
     }
     return l;
 }
int Solution::lPalin(ListNode* A) {
    if(A==NULL) return 1;
    int len = findLen(A);
    int half;
    if(len%2 == 1) {
        half = len/2+1;
    } 
    else {
        half = len/2;
    }
    ListNode* mid = A;
    ListNode* prev = NULL;
    for (int i = 0; i < half; i++) {                 // reach to the middle of the LinkedList
        prev = mid;
        mid = mid->next;
    }
    ListNode* curr = mid;
    prev = NULL;
    ListNode* next = NULL;
    while(curr!=NULL) {                             // keep on reversing the linked list till the end of the linked list 
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ListNode* p = prev;
    ListNode* q  = A;
    while(p!=NULL && q!=NULL) {
        if(p->val != q->val) {
            return 0;
        }
        p = p->next;
        q = q->next;
    }
    return 1;
    
    
}

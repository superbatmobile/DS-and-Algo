/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (!head || !head->next)
        return head;
    int i, j;
    struct ListNode *p, *cur, *q;
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode ));
    res->next = head;
    p = res;
    for (i = 1; i < left; i++){
        p = p->next;
    }
    cur = p->next;
    for (i = left; i < right; i++){
        q = cur->next;
        cur->next = q->next;
        q->next = p->next;
        p->next = q;
    }
    return res->next;
}
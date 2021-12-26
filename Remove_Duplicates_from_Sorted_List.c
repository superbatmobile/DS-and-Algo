/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head)
        return NULL;
    struct ListNode* cur = head;
    struct ListNode* nex = head->next;
    while(nex){
        while (cur->val == nex->val){
            cur->next = nex->next;
            nex = cur->next;
            if (!nex)
                return head;
        }
        cur = cur->next;
        nex = nex->next;
    }
    return head;
}
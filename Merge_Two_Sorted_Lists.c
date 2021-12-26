/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (!list1 && !list2)
        return NULL;
    if (!list1 || !list2)
        return list1 ? list1 : list2;
    struct ListNode* merge_list = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* temp = merge_list;
    while (list1 && list2){
        if(list1->val > list2->val){
            temp->next = list2;
            list2 = list2->next;
        }else{
            temp->next = list1;
            list1 = list1->next;
        }
        temp = temp->next;
    }
    if (list1)
        temp->next = list1;
    if (list2)
        temp->next = list2;
    return merge_list->next;
}
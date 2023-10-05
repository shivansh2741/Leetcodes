/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* list1,ListNode* list2){
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;

        ListNode* newhead;

        if(list1->val > list2->val){
            newhead = list2;
            newhead->next = solve(list1,list2->next);
        }
        else{
            newhead = list1;
            newhead->next = solve(list1->next,list2);
        }

        return newhead;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;

        return solve(list1,list2);   
    }
};
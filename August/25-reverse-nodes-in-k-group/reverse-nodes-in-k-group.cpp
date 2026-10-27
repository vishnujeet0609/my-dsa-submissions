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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxt = NULL;
        ListNode* temp1 = head;
        while (cur != NULL) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return {prev, temp1};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        ListNode* cur = temp;
        ListNode* actualPrev = NULL;
        ListNode* actualRoot = NULL;
        while (temp != nullptr) {
            cnt++;
            if (cnt == k) {
                ListNode* nxt = temp->next;
                temp->next = NULL;
                auto actualCur = reverse(cur);
                if(actualRoot == NULL){
                    actualRoot = actualCur.first;
                }
                if(actualPrev != NULL){
                    actualPrev->next = actualCur.first;
                }
                actualPrev = actualCur.second;
                cur = nxt;
                temp = nxt;
                cnt = 0;
            } else {
                temp = temp->next;
            }
        }
        actualPrev->next = cur;
        return actualRoot;
    }
};

// pair<ListNode*, ListNode*> reverse(ListNode* head) {
//     ListNode* prev = NULL;
//     ListNode* cur = head;
//     ListNode* nxt = NULL;
//     ListNode* temp1 = head;
//     while (cur != NULL) {
//         nxt = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = nxt;
//     }
//     return {prev, temp1};
// }

// ListNode* reverseList(ListNode* head, int K) {
//     // Complete the function
//     ListNode* temp = head;
//     int cnt = 0;
//     ListNode* cur = temp;
//     vector<ListNode*> v;
//     while (temp != nullptr) {
//         cnt++;
//         if (cnt == K) {
//             ListNode* nxt = temp->next;
//             temp->next = NULL;
//             v.push_back(cur);
//             cur = nxt;
//             temp = nxt;
//             cnt = 0;
//         } else {
//             temp = temp->next;
//         }
//     }
//     auto p = reverse(v[0]);
//     ListNode* st = p.first;
//     for (int i = 1; i < v.size(); i++) {
//         auto p2 = reverse(v[i]);
//         p.second->next = p2.first;
//         p = p2;
//     }
//     return st;
// }
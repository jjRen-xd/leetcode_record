/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* q = head;
        for(ListNode* p = head; p != nullptr; p = p->next){
            if(p->val == val){
                if(p == head){
                    head = head->next;
                }
                else{
                    q->next = p->next;
                }
            }
            else{
                q = p;
            }
        }
        return head;
    }
};
// @lc code=end

int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i<=5; i++){
        ListNode* q = new ListNode(i);
        p->next = q;
        p = q;
    }
    ListNode* res = sol.removeElements(head, 3);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}

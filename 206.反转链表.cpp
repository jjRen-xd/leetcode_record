/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // 双指针
    ListNode* reverseList_1(ListNode* head) {
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        ListNode* curr = head;
        while(curr){
            after = curr->next;
            curr->next = before;
            before = curr;
            curr = after;
        }
        return before;
    }
    // 递归
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* curr){
        if(curr == nullptr){
            return pre;
        }
        ListNode* tmp = curr->next;
        curr->next = pre;

        return reverse(curr, tmp);
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
    ListNode* res = sol.reverseList(head);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;    
}
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        for(ListNode* curr = head; curr; curr=curr->next){
            length++;
        }
        int removePos = length-n;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        for(int i = 0; i<removePos; i++){
            pre = curr;
            curr = curr->next;
        }
        if(pre){
            pre->next = curr->next;
            delete curr;
            return head;
        }
        else{
            return curr->next;
        }
    }
};
// @lc code=end
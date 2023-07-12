/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* newList = new ListNode(0);
        ListNode* resList = newList;
        while(p && q){
            if(p->val >= q->val){
                newList->next = q;
                q = q->next;
            }
            else{
                newList->next = p;
                p = p->next;  
            }
            newList = newList->next;
        }
        if(p){
            newList->next = p;
        }
        else{
            newList->next = q;
        }

        return resList->next;
    }
};
// @lc code=end


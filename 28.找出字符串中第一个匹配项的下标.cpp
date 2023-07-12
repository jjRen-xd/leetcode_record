/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include<iostream>
#include<string>

using namespace std;
// @lc code=start
class Solution {
public:
    int strStr_1(string haystack, string needle) {
        // 暴力解法
        int res = -1;
        for(int i = 0; i<haystack.size(); i++){
            bool isSub = true;
            for(int j = 0; j<needle.size(); j++){
                if (haystack[i+j]!=needle[j]){
                    isSub = false;
                    break;
                }
            }
            if(isSub){
                res = i;
                break;
            }
        }
        return res;
    }
    /*
    int strStr(string haystack, string needle) {
        // KMS算法, 减一右移版本
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);

        int j = -1;
        for(int i = 0; i<haystack.size(); i++){
            // 不匹配
            while(j>=0 && haystack[i] != needle[j+1]){
                j = next[j];    // 寻找之前匹配的位置
            }
            if(haystack[i] == needle[j+1]){
                j++;
            }
            if(j == needle.size()-1){
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
    void getNext(int* next, const string& s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i<s.size(); i++){
            // 前后缀不相同
            while(j>=0 && s[i] != s[j+1]){ 
                j = next[j];
            }
            // 找到相同的前后缀
            if(s[i] == s[j+1]){
                j++;
            }
            // 将前缀的长度赋给next[i]
            next[i] = j;
        }
    }
    */
int strStr(string haystack, string needle) {
        // KMS算法, next表就为前缀表版本
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);

        int j = 0;
        for(int i = 0; i<haystack.size(); i++){
            // 不匹配
            while(j>0 && haystack[i] != needle[j]){
                j = next[j-1];    // 寻找之前匹配的位置
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i<s.size(); i++){
            // 前后缀不相同
            while(j>0 && s[i] != s[j]){ 
                j = next[j-1];
            }
            // 找到相同的前后缀
            if(s[i] == s[j]){
                j++;
            }
            // 将前缀的长度赋给next[i]
            next[i] = j;
        }
    }
};
// @lc code=end


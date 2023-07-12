#include <iostream>
#include <string>
#include <vector>

using namespace std;


string removeKnums(string num, int k){
    vector<char> stack;
    for(char digit: num){
        while(stack.size()>0 && stack.back() > digit && k){
            stack.pop_back();
            k -= 1;
        }
        stack.push_back(digit);
    }
    for(; k>0; k--){
        stack.pop_back();
    }
    string result = "";
    bool zeroStart = true;
    for(auto digit: stack){
        if(digit == '0' && zeroStart){
            continue;
        }
        zeroStart = false;
        result += digit;
    }
    return result == "" ? "0": result;
}

int main(){
    string num = "1412219";
    int k = 3;
    // 手动输入k和num
    // int k;
    // string num;
    // cout<<"Please input k: ";
    // cin>>k;
    // cout<<"Please input num: ";
    // cin>>num;
    string result  = removeKnums(num, k);
    cout<< result <<endl;
    return 0;
}
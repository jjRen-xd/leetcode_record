
// 有一个核心交易系统接口被N个上游系统调用，每个上游系统的调用量R=[R1,R2.....,RN],
// 由于核心交易系统集群故障，需要暂时系统降级限制调用，核心交易系统能接受的最大调用量为cnt。
// 设置降级规则如下:如果sum(R1,R2,....,RN)小于等于cnt，则全部可以正常调用，返回-1;
// 如果sum(R1,R2,....,RN)大于ent，设置一个闻值limit，如果某个上游系统发起的调用量超过过limit，
// 就将该上游系统的调用量限制为limit，其余未达到limit的系统可以正常发起调用。求出这个最大的limit(limit可以为0)此题目对效率有要求，
// 请选择高效的方式

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int find_max_limit(vector<int>& R, int cnt) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int max_limit = 0;
        for(int i=0; i<R.size(); i++){
            right = max(right, R[i]);
            sum += R[i];
        }
        if(sum <= cnt){
            return -1;
        }
        while(left <= right){
            int mid = left+(right-left)/2;
            if(check(R, mid, cnt)){
                max_limit = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return max_limit;
    }
    bool check(vector<int>& R, int limit, int cnt){
        int sum = 0;
        for(int i=0; i<R.size(); i++){
            if(R[i] > limit){
                sum += limit;
            }
            else{
                sum += R[i];
            }
        }
        return sum <= cnt;
    }
};

int main(){
    Solution s;
    vector<int> R = {1, 7, 8, 8, 10, 2, 4, 9};
    int cnt = 7;
    cout << s.find_max_limit(R, cnt) << endl;
    return 0;
}

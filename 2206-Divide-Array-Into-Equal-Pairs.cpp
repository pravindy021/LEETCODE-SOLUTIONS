class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>cnt;
        for(auto u:nums){
            cnt[u]++;
        }
        for(auto u:nums){
            if(cnt[u]%2){
                return false;
            }
        }
        return true;
    }
};
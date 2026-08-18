class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n= nums.size();
        if(k == nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1){
            sort(nums.rbegin(), nums.rend());
            for(int i=0 ; i<n ; i++){
                if(i == 0){
                    if(n > 1 && nums[i] != nums[i+1]){
                        return nums[i];
                    }
                }else if(i == n-1){
                    if(nums[i] != nums[i-1]){
                        return nums[i];
                    }
                }else if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                    return nums[i];
                }
            }

            return -1;
        }
        int f = nums[0];
        int s = nums[nums.size()-1];
        
        for(int i=1; i<n; i++){
            if(nums[i] == f){
                f = -1;
                break;
            }
        }

        for(int i=0 ; i<n-1 ; i++){
            if(nums[i] == s){
                s = -1;
                break;
            }
        }

        return max(f, s);
    }
};
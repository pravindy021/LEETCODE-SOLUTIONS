class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n);

        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + stones[i];
        }

        // now why ans is from the last, because suppose if alice choose all the stones then bob has nothing to chooose therefore we start from the last
        int ans=prefix[n-1];
        
        // also why till i>=1 because the question says  choose "x>1"
        for(int i=n-2; i>=1; i--){
            ans = max(ans, prefix[i] - ans);
        }

        return ans;
    }
};
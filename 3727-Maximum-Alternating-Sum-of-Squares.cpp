class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n =  nums.size();
        vector<long long> squares(n);
        for(int i = 0; i< n; i++){
            squares[i]=(long long)nums[i]*nums[i];
        }
        sort(squares.begin(), squares.end());

        long long max_score = 0;
        int num_neg =n / 2;

        for (int i=0; i<num_neg; ++i){
            max_score -= squares[i];
        }
        for (int i=num_neg; i<n; ++i){
            max_score += squares[i];
        }
        return max_score;
        
    }
};
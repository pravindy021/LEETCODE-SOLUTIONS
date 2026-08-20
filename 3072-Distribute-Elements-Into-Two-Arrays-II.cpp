class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> a;
        vector<int> b;
        vector<int> A;
        vector<int> B;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        A.push_back(nums[0]);
        B.push_back(nums[1]);
        for(int i=2; i<n; i++)
        {
            int ita=upper_bound(A.begin(), A.end(), nums[i])-A.begin();
            int x = A.size()-ita;
            int itb=upper_bound(B.begin(), B.end(), nums[i])-B.begin();
            int y = B.size()-itb;
            if(x>y)
            {
                a.push_back(nums[i]);
                A.insert(A.begin()+ita, nums[i]);
            }
            else if(y>x)
            {
                b.push_back(nums[i]);
                B.insert(B.begin()+itb, nums[i]);
            }
            else if(a.size()<b.size())
            {
                a.push_back(nums[i]);
                A.insert(A.begin()+ita, nums[i]);
            }
            else if(b.size()<a.size())
            {
                b.push_back(nums[i]);
                B.insert(B.begin()+itb, nums[i]);
            }
            else
            {
                a.push_back(nums[i]);
                A.insert(A.begin()+ita, nums[i]);
            }
        } 
        vector<int> ans;   
        for(auto it:a)
        {
            ans.push_back(it);
        }
        for(auto it:b)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>hash(26,0),used(26,0);
        for(auto ch : s) hash[ch-'a']++;

        string ans="";
        for(auto ch : s)
        {
            hash[ch-'a']--;
            if(used[ch-'a']>0)continue;
            while(!ans.empty() && ans.back()>ch && hash[ans.back()-'a']>0)
            {
                used[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans+=ch;
            used[ch-'a']=1;
        }
    return ans;
    }
};
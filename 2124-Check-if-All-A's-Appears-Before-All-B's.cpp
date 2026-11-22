class Solution {
public:
    bool checkString(string s) {
        string valid = s;
        sort(valid.begin(),valid.end());
        if(s==valid) return true;
        else return false;
    }
};
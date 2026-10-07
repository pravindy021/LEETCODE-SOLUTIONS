class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
             return false;

        int original = x;
        int reversed_num=0;
        int digit;

        while (x>0)
            digit= x%10;
            reversed_num= reversed_num*10+digit; 
            x=10;

        return original ==reversed_num;
        
    }
};
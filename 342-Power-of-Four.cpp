class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
        return 0;

        while(n!=1){
        if(n%4 == 1)
            return 0;
            n= n/4;


        }
        return 1;
        
    }
};
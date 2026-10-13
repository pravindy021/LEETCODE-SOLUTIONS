class Solution {
public:
    bool isPrime(int n){
        if(n<=1)return false;
        if(n==2)return true;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        if(!isPrime(num)) return false;
        string str = to_string(num);
        int n = str.length();
        int prefix = 0;
        int suffix = 0;
        for(int i = 0;i<n;i++){
            prefix = prefix*10 + (str[i]-'0');
            if(!isPrime(prefix))return false;
        }
        for(int i = 0;i<n;i++){
            suffix = stoi(str.substr(i));
            if(!isPrime(suffix))return false;
        }
        return true;
    }
};
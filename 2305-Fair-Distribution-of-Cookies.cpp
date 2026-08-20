class Solution {
public:
int n;

void solve(int idx, vector<int>& cookies, vector<int>& children , int k){
    if(idx==n){
        int unfair= *max_element(begin(children),end(children));
        result = min(result, unfair);
        return;
    }
    int cookie = cookies[idx];
    for(int i =0; i<k ; i++){
        children[i]+= cookie;
        solve(idx+1,cookies,children,k);
        children[i] -= cookie;
    }
}


int result = INT_MAX;
    int distributeCookies(vector<int>& cookies, int k) {
         n = cookies.size();
        vector<int> children(k,0);
        solve(0,cookies,children,k);
        return result;        
    }
    
};
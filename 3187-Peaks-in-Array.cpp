class Solution {
public:
    int sz;
    vector<int> tr;

    void update(int li, int ri, int ni, int idx, int val) {
        if(ri - li == 1) {
            tr[ni] = val;
            return;
        }

        int m = (li + ri) >> 1;

        if(idx < m)
            update(li, m, ni * 2 + 1, idx, val);
        
        else
            update(m, ri, ni * 2 + 2, idx, val);

        tr[ni] = tr[ni * 2 + 1] + tr[ni * 2 + 2];
    }

    int query(int li, int ri, int ni, int l, int r) {
        if(l <= li && r >= ri)
            return tr[ni];

        if(l >= ri || r <= li)
            return 0;

        int m = (li + ri) >> 1;
        return query(li, m, ni * 2 + 1, l , r) + query(m, ri, ni * 2 + 2, l, r);
    }

    vector<int> countOfPeaks(vector<int>& A, vector<vector<int>>& Q) {
        int n = A.size();

        sz = 1;
        while(sz < n)
            sz <<= 1;

        tr.assign(sz << 1, 0);

        for(int i = 1; i < n - 1; ++i)
            if(A[i] > A[i - 1] && A[i] > A[i + 1])
                update(0, sz, 0, i, 1);   

        vector<int> res;

        for(auto& q : Q) {
            if(q[0] == 1) {
                int l = q[1], r = q[2];
                res.push_back(0);

                if(l + 1 < r) 
                    res.back() = query(0, sz, 0, l + 1, r);
            }

            else {
                int idx = q[1], val = q[2];
                A[idx] = val;

                for(int i = max(1, idx - 1); i <= min(n - 2, idx + 1); ++i) 
                    update(0, sz, 0, i, A[i] > A[i - 1] && A[i] > A[i + 1]);
            }
        }

        return res;
    }
};
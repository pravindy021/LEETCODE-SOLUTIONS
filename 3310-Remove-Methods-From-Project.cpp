constexpr int N=1e5, M=2e5;
struct Edge{ int v, nxt=-1; };
Edge E[M];
int eIdx=0;
int adj[N];// heads of linked lists
inline void addEdge(int u, int v){
    E[eIdx]={v, adj[u]};
    adj[u]=eIdx++;
}
uint8_t vis[N];
int q[N], front, back;
class Solution {
public:
    static inline void bfs(int k){
        front=back=0;// reset q
        q[back++]=k;
        vis[k]=1;
        while(front<back){
            int u=q[front++];
            for(int idx=adj[u]; idx!=-1; idx=E[idx].nxt){
                const int v=E[idx].v;
                if (vis[v]!=0) continue;
                q[back++]=v;
                vis[v]=1;
            }
        }
    }
    static vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        eIdx=0;
        memset(adj, -1, n*sizeof(int));
        memset(vis, 0, n);
        for(auto& e : invocations){
            const int u=e[0], v=e[1];
            addEdge(u, v);
        }
        bfs(k);
        bool cnnt1=0;
        for(auto& e : invocations){
            const int u=e[0], v=e[1];
            if ((vis[u]==0) & (vis[v]==1)){
                cnnt1=1;
                break;
            }
        }
        vector<int> ans;
        if (cnnt1){
            ans.resize(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }
        ans.reserve(n);
        for(int i=0; i<n; i++){
            if (vis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
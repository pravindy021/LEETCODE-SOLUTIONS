class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r=0, c= 0;
        set<pair<int,int>> visited;
        visited.insert({r, c});

        map<char, pair<int,int >>directions ={
            {'R', {0, 1}},
            {'L', {0, -1}},
            {'D', {1, 0}},
            {'U', {-1, 0}}
        };
        while (true){
            char move = grid [r][c];

            int dr = directions[move].first;
            int dc = directions[move].second;
            int nr = r+dr;
            int nc = c+dc;

            if (nr<0 || nr>= n || nc<0 || nc>= m || visited.count({nr, nc})){
                break;
            
            }

            r = nr;
            c = nc;
            visited.insert({r,c});
            
        }
        return{ r, c};
        
    }
};
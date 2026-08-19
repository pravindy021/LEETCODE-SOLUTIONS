class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> rowBookings;
        for(int i=0;i<reservedSeats.size(); i++){
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];

            if (rowBookings.find(row)==rowBookings.end()){
                rowBookings[row]=vector<bool>(11, false);
            }
            rowBookings[row][col]=true;


        }
        long long totalFamilies = 2LL*n;

        for(auto const& pair : rowBookings){
        vector<bool> seats =pair.second;

        bool leftBlocked = seats[2] ||seats[3] ||seats[4] ||seats[5];
        bool rightBlocked = seats[6] ||seats[7] ||seats[8] ||seats[9];
        bool middleBlocked = seats[4] ||seats[5]|| seats[6] ||seats[7];

        if(leftBlocked && rightBlocked && middleBlocked){
            totalFamilies = totalFamilies-2;

        }
        else if(leftBlocked && rightBlocked){
            totalFamilies = totalFamilies-1;

        }
        else if (leftBlocked ||rightBlocked){
            totalFamilies=totalFamilies-1;
        }

        }

        return totalFamilies;
    }
    

    
};
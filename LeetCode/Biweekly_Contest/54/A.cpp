class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> covered(50, false);      
        for(int i = 0; i < ranges.size(); i++) for(int j = ranges[i][0]; j <= ranges[i][1]; j++) covered[j]=1;
        for(int i = left; i <= right; i++) if(!covered[i]) return false;
            return true;
    }
};

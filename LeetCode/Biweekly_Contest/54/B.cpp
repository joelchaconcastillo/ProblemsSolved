class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
         long long sumchalk=0;
        for(auto &i:chalk) sumchalk +=i;
        k %=sumchalk;
        sumchalk=0;
        for(int i = 0; i < chalk.size(); i++)
        {
            sumchalk +=chalk[i];
                if(sumchalk > k) return i;
        }
        return 0;
    }
};

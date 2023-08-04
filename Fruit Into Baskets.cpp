class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 1) return 1;
        int ans = 0, i = 0, j = 0;
        unordered_map<int, int> mpp;
        while(j < fruits.size()) {
            mpp[fruits[j]]++;
            if(mpp.size() <= 2) {
                ans = max(ans, j-i+1);
                j++;
            }
            else if(mpp.size() > 2) {
                while(mpp.size() > 2) {
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0) {
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        } 
        return ans;
    }
};

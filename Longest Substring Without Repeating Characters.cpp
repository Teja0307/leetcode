class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        unordered_map<char, int> mpp;
        while(j < s.length()) {
            mpp[s[j]]++;
            int cnt = j-i+1;
            if(mpp.size() == cnt) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while(mpp.size() < cnt) {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) {
                        mpp.erase(s[i]);
                    }
                    i++;
                    cnt--;
                }
                j++;
            }
        }
        return ans;
    }
};

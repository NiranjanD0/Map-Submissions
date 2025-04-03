class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;    
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) { 
                int currentNum = num;
                int streak = 1;
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }
                maxLength = max(maxLength, streak);
            }
        }
        return maxLength;
    }
};
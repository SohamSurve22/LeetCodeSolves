class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            if (lastIndex.find(c) != lastIndex.end()) {
                left = max(left, lastIndex[c] + 1);
            }

            lastIndex[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
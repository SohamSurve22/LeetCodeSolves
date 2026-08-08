#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();

        std::vector<int> last_match(m, -1);
        
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last_match[j] = i;
                j--;
            }
            i--;
        }
        
        std::vector<int> ans(m);
        bool can_skip = true; 
        j = 0; 

        for (i = 0; i < n; ++i) {
            if (j == m) break;
            
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            } 

            else if (can_skip && (j == m - 1 || i < last_match[j + 1])) {
                can_skip = false;
                ans[j] = i;
                j++;
            }
        }

        return (j == m) ? ans : std::vector<int>();
    }
};

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;
        for (char c : s)
            if (c == '1') originalOnes++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> runs;

        for (int i = 0; i < m; ) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int bestGain = 0;

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                bestGain = max(bestGain,
                               runs[i - 1].second + runs[i + 1].second);
            }
        }

        return originalOnes + bestGain;
    }
};
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int d : digits)
            freq[d]++;

        int count = 0;

        for (int num = 100; num <= 998; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;
            int a = x % 10;       // units
            x /= 10;
            int b = x % 10;       // tens
            x /= 10;
            int c = x;            // hundreds

            // Temporarily consume the digits
            if (freq[a] == 0 || freq[b] == 0 || freq[c] == 0)
                continue;

            int need[10] = {};
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                count++;
        }

        return count;
    }
};
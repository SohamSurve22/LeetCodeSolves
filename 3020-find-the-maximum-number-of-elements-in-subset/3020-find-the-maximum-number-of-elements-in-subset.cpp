class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> frequencyMap;
        for (int number : nums) {
            ++frequencyMap[number];
        }
      

        int maxLength = frequencyMap[1] - (frequencyMap[1] % 2 ^ 1);
      
        frequencyMap.erase(1);

        for (auto [baseValue, frequency] : frequencyMap) {
            int currentLength = 0;
            long long currentValue = baseValue;

            while (frequencyMap.count(currentValue) && frequencyMap[currentValue] > 1) {
                currentValue = currentValue * currentValue;
                currentLength += 2; 
            }
          

            currentLength += frequencyMap.count(currentValue) ? 1 : -1;

            maxLength = max(maxLength, currentLength);
        }
      
        return maxLength;
    }
};
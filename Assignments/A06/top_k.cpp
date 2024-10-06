class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //minimum heap to hold only the top K frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_h;
        //map to hold each element and its frequency
        map<int, int> freq;
        //vector to return final answers
        vector<int> top;
        
        //loop through nums and count frequency for each num
        for(const auto& num : nums) {
            freq[num]++;
        }

        //push frequency then num into min heap so greater will compare the frequency
        for(const auto& pair : freq) {
            min_h.push({pair.second, pair.first});

            //make sure min heap stays of size k
            if(min_h.size() > k)
                min_h.pop();
        }

        //push the top K frequent onto top vector
        while(!min_h.empty()) {
            top.push_back(min_h.top().second);
            min_h.pop();
        }

        //return the top K frequen elements
        return top;
    }
};
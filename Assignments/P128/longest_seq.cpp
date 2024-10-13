class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Hash table to hold nums for easy lookup
        //Helps to maintain O(n) time constraint
        unordered_set<int> n2(nums.begin(), nums.end());
        
        //Hold final longest sequence of numbers to return at completion
        int fin_seq = 0;

        //If size of nums is 0, longest sequence is 0
        if(nums.size() == 0)
            return 0;

        //If size of nums is 1, longest sequence is 1
        if(nums.size() == 1)
            return 1;

        //If size of nums larger than 1, loop
        //n times where n is the size of nums
        for(int i = 0; i < nums.size(); i++) {

            //Search hash table for a value less than nums[i]
            //If not found, find() returns an iterator pointing to the end
            if(n2.find(nums[i] - 1) == n2.end()) {

                //Once no smaller num is found create a value for the current longest sequence
                int curr_seq = 1;

                //Search through the hash table to see if the next in-order value is present
                //Ex: if nums[i] is 1, search for 2 then 3 then 4... Increment the current longest
                //Sequence on each find until no more of the current sequence is found
                while(n2.find(nums[i] + curr_seq) != n2.end())
                    curr_seq++;

                //Store the max value between curr_seq and fin_seq in fin_seq
                //This compares the sequence length from the current loop to 
                //The previous longest sequence
                fin_seq = max(curr_seq, fin_seq);
            }
        }

        return fin_seq;
    }
};
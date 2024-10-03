class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Create a Minimum Heap by implementing a priority queue
        //that uses greater to find the largest elements in nums
        priority_queue<int, vector<int>, greater<int>> mh;

        //loop through nums and push gretest vals into min heap
        for(int num : nums) {
            mh.push(num);

            //Keep the min heap to a size of k
            if(mh.size() > k)
                mh.pop();
        }

        //once finished, the top of min heap will be Kth largest value
        return mh.top();
    }
};
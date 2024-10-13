class Solution {
public:
    int hammingWeight(int n) {
        //Total count of set bits
        int sb = 0;

        //Loop as long as n has value
        while(n > 0) {
            //Check the least significant bit, if 1 increment sb
            if(n & 1)
                sb++;
            
            //Shift all bits to the right and check loop again
            n = n >> 1;
        }

        return sb;
    }
};
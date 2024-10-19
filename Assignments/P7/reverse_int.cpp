class Solution {
public:
    int reverse(int x) {
        //Use a long to hold the reversed value in case it overflows it for the time being
        long rev = 0;
        //Hold the last digit of x that will be placed first in rev
        int curr;

        while(x != 0) {
            //Get the current last digit of x
            curr = x % 10;
            //Remove the last digit from x
            x = x / 10;
            //Place the digit into rev, placing each new digit after the previous
            rev = (rev * 10) + curr;
        }

        //Check if rev is out of the 32-bit range constraint, return 0 if so
        if(rev < INT_MIN || rev > INT_MAX)
            return 0;

        //Return the reversed integer if it is not out of the 32-bit range
        else
            return rev;
    }
};
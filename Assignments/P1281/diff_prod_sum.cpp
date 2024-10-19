class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;

        while(n != 0) {
            //Multiply prod by the last digit of n
            //Add the last digit of n to sum
            prod *= n % 10;
            sum += n % 10;

            //Dividing n by 10 will drop the last digit and move the others to the right
            n /= 10;
        }

        //Return the difference of prod and sum
        return prod - sum;
    }
};
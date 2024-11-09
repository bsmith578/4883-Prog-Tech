#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Number of test cases | Budget | Number of categories | Number of garments in each category
    int N, M, C, K;

    cin >> N;

    //Iterate through each test case
    while(N--) {
        cin >> M >> C;

        //Create a 2D vector to hold the prices of each garment model
        vector<vector<int>> prices(C);

        //Loop through the categories and fill the prices
        for(int i = 0; i < C; i++) {
            cin >> K;
            vector<int> temp(K);

            for(int j = 0; j < K; j++)
                cin >> temp[j];

            prices[i] = (temp);
        }

        /* Create a bool DP table of size (M + 1) x (C + 1) and set each cell to false */
        //Allows program to set a cell to true if 'm' dollars can be spent without going over
        //  budget, where 'm' is the price of the current garment plus the price of the previous
        
        //Setting dp[0][0] to true means we can spend $0 on 0 garments, providing a
        //  base case to start filling the table
        vector<vector<bool>> dp(M + 1, vector<bool>(C + 1, false));
        dp[0][0] = true;

        for(int cat = 1; cat <= C; cat++) {             //Loop through each category 1 to C
            for(int s = 0; s <= M; s++) {               //Loop through each possible spending amount from 0 to M
                if(dp[s][cat - 1]) {                    //Check if s dollars were spent in the previous category
                    for(int price : prices[cat - 1]) {  //If so, iterate through each garment price within the current category
                        if(s + price <= M)              //If the previous amount spent plus the price of the current garment is within budget,
                            dp[s + price][cat] = true;  //set the value of that cell to true
                    }
                }
            }
        }

        //Set the variable maxSpent to -1 to indicate no money spent, and possibly no solution
        //Loop from the highest value in the last column down to the lowest, if a value is found
        //that is the most money that can be spent when all necessary garments are purchased
        int maxSpent = -1;
        for(int mx = M; mx >=0; mx--) {
            if(dp[mx][C]) {
                maxSpent = mx;
                break;
            }
        }

        //If no values are found within the last column,
        //maxSpent stays at -1 and there is no solution
        if(maxSpent == -1)
            cout << "no solution\n";

        else
            cout << maxSpent << "\n";
    }
}
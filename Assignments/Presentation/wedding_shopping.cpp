/*
* Bottom-Up, iterative dynamic programming approach to UVa 11450: Wedding Shopping
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Number of test cases | Budget | Number of categories of garments | Number of garments in each category
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

            prices.push_back(temp);
        }

        /* Create a bool DP table of size (M + 1) x (C + 1) and set each cell to false */
        //Allows program to set a cell to true if 'm' dollars can be spent on each garment
        //  within each category without exceeding the budget
        
        //Setting dp[0][0] to true means we can spend $0 on 0 garments, providing a
        //  base case to start filling the table
        //bool dp = new bool[M + 1][C + 1];
        //fill(&dp[0][0], &dp[0][0] + ((M + 1) * (C + 1)), false);
        //dp[0][0] = true;
        
        vector<vector<bool>> dp(M + 1, vector<bool>(C + 1, false));
        dp[0][0] = true;

        for(auto& v : dp) {
            for(const auto& b : v)
                cout << b << ' ';

            cout << endl;
        }
    }
}
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

        for(const auto& v : prices) {
            for(int price : v)
                cout << price << endl;
        }
    }
}
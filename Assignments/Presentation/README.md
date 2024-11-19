## 11450 - Wedding Shopping
### Brett Smith 
### Description:

For this problem you have been invited to be a part of a friend's wedding but you do not have any
clothes for the occasion. You have a set budget and you must buy a certain number of clothing items
for the wedding. When choosing each item, you are provided with a few different models of each item
and each has a different price. The objective is to purchase one model of each clothing item and spend
the most amount of money possible without exceeding your budget.

### Input:

The first line of input is an integer `N` which represents the number of test cases. The next line
contains your budget `M` and the number of clothing items you must purchase `C`. Next, there are `C`
lines where the first integer `K` represents the number of models for that specific item and the next
`K` integers represent the price for each model. As stated above, the program must determine the maximum
amount of money that can be spent by purchasing one model of each clothing item without going over
budget. At the end of each test case the program will print the max amount spent, if possible, otherwise
it prints `no solution`.

### Constraints:

`1 <= M <= 200`

`1 <= C <= 20`

`1 <= K <= 20`

### Approach:

Bottom-up, or tabulation, dynamic programming approach. This approach allows the program to store
the results of each smaller subproblem and build upon each to eventually reach the desired end result.

* Step 1: Reading and Storing Initial Data
  1. Read in test cases iterate through each.
  2. Create `prices` and fill with garment prices.

  ![reading](https://github.com/bsmith578/photos/blob/main/4883-Pres-Pics/reading_storing_initial.png)

* Step 2: Creating and Filling the DP Table
  1. Initialize a DP table, `dp`, using a 2D bool vector of size [M + 1][C + 1] where each cell starts as false
  2. Set `dp[0][0]` to true. Provides a base case, or starting point, to fill the table.
  3. Iterate over each column. If a cell is true, meaning you have already spent `s` dollars on `cat` categories of garments,
     iterate through the garment prices in the current category. If the previous amount spent plus the price of the current
     garment is less than the budget, set `dp[s + price][cat]` to true.

  ![DP Table](https://github.com/bsmith578/photos/blob/main/4883-Pres-Pics/create_fill_dp.png)

* Step 3: Finding the Max Amount that can be spent
  1. Start with `maxSpent = -1`. Allows to initially show that no money has been spent.
  2. Iterate over the last column in the table from the bottom-up. The cell furthest at the bottom that is true
     represents the maximum amount of money that can be spent from buying one garment from each category. If a
     cell is found meeting the criteria, set its value to `maxSpent` and print it.
  3. If no cell meets the criteria, `maxSpent` stays at -1, representing we could not stay in budget, and the program prints `no solution`.

  ![maxSpent](https://github.com/bsmith578/photos/blob/main/4883-Pres-Pics/find_maxSpent.png)

### Associated Costs

* Time Complexity
  - Since filling the DP table generates the dominant time complexity as it iterates
    through the categories(C), the budget(M), and number of garments in each category(K),
    this gives a final time complexity of:
    - *O*(C x M x K)
 
* Space Complexity
  - Here we have two 2D vectors, `prices` and `dp`, where the sizes are `C x K` and
    `(M + 1) x (C + 1)` respectively, giving a final space complexity of:
    - *O*((C x K) + (M x C))

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [P11450](./p11450.pdf) | PDF Problem Description                                        |
|   2   | [wedding_shopping.cpp](./wedding_shopping.cpp) | solution file                          |
|-------| -------------------------- | ---------------------------------------------------------- |
|   3   | [in1](./in1) | Sample input provided in the problem description                         |
|   4   | [out1](./out1) | Output when program ran with in1 as input                              |
|-------| -------------------------- | ---------------------------------------------------------- |
|   5   | [in2](./in2) | Sample input from uDebug                                                 |
|   6   | [out2](./out2) | Output when program ran with in2 as input                              |

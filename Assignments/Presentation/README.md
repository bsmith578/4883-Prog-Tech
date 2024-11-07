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

Bottom-up, iterative dynamic programming approach. 

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
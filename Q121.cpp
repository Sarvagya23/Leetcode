class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> maxVal(n,prices[n-1]);
        int ans = 0;
        for(int i = 1; i < n; i++){
            maxVal[n-i-1] = max(maxVal[n-i],prices[n-i-1]);
            ans = max(ans,maxVal[n-i-1]-prices[n-i-1]);
        }
        return ans;

    }
};
 
 /*
Problem: Find the maximumProfit a person can get after buying and selling the stock.
Intuition: We know the cost of a stock on each day, if at a particular day we get to know the maximum price of a stock for all the upcoming days we can directly find the difference
Solution: 
	1. We can create an array that takes the max of the stock price from the end of the array
	2. With this knowledge for a particular index i, we will have the maximum stock price from index i to index n-1 (The last element's index).
	3. Now we can directly take the difference at index i (the price of stock at index i and the maximum price of stock from index i to index n-1).*/
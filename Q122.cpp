class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            if(prices[i] <= prev && prices[i] <= prices[i+1]){
                int valley = prices[i];
                while(i < n-1 && prices[i] <= prices[i+1]){
                    i++;
                }
                ans += prices[i]-valley;
            }
            prev = prices[i];
        }
        return ans;
    }
};

/*
Problem: Find the maximumProfit a person can get after buying and selling the stock multiple times.
Intuition: If we find a stock that is a localMinima we can take that as the buying price and find the maximum selling price for that stock until it shoots down again.
Solution:
	1. We can find the localMinima by looking at the adjacent indices.
	2. With this knowledge for a particular index i, we will iterate in the while loop till the time stock price keeps on going higher and sell it the the localMaxima.
	3. Now we can directly take the difference of the localMinima and localMaxima and repeat the process until the end of the array.
//https://leetcode.com/problems/climbing-stairs/description/


/* ========================== RECURSIVE ===================================*/
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 1;

        int oneStep = climbStairs(n-1);
        int twoStep = 0;
        if(n>1)
            twoStep = climbStairs(n-2);
        return oneStep + twoStep;
    }
};

//TC: O(2^n)
//SC: O(n)


/* ========================== Memoization ===================================*/

class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//We are not returning dp[n] as we are also considering the base case while returning. If n==1, we return the solve function answer.
//If you want to return dp[n], then handle base cases in climbStairs.


/* ========================== Tabulation ===================================*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};


/* ========================== Space optimization ===================================*/

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
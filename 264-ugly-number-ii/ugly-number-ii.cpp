class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> dp(n);
        dp[0]=1;

        int i=0, j=0, k=0;
        int two, three, five;

        for(int p=1; p<n; p++){
            two = dp[i]*2;
            three = dp[j]*3;
            five = dp[k]*5;

            dp[p] = min({two, three, five});

            i=(dp[p]==two)?i+1:i;
            j=(dp[p]==three)?j+1:j;
            k=(dp[p]==five)?k+1:k;
        }

        return dp[n-1];
    }
};
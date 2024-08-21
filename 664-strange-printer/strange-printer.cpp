class Solution {
public:
    static void shorten(string& s, int& n){
        int len = s.size();
        n=1;

        char curr;
        for(int l=0, r=1; r<len; r++){
            curr = s[r];
            while(l<r && s[l]==curr) l++;
            if(r<len && s[l]!=curr){
                s[n++]=s[r];
                l=r;
            }
        }
        s.resize(n);
    }
    static int strangePrinter(string s) {
        int n;
        shorten(s, n);

        int dp[101][101]={0};
        for(int i=n-1; i>=0; i--){
            dp[i][i]=1;
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
                int x = dp[i][j-1]+1;
                for(int k=i+1; k<j-1; k++){
                    if(s[k]==s[j]){
                        x = min(x, dp[i][k-1]+dp[k][j-1]);
                        k++;
                    }
                }
                dp[i][j]=x;
            }
        }
        return dp[0][n-1];
    }
};

auto init=[](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios::sync_with_stdio(0);
}();
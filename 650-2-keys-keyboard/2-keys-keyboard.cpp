class Solution {
public:
    static int minSteps(int n) {
        if(n==1) return 0;

        int steps = 0;
        int prev = 2;

        while(n>1){
            while(n%prev == 0){
                steps+=prev;
                n/=prev;
            }
            prev++;
        }
        return steps;
    }
};

auto init=[](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios::sync_with_stdio(0);
}();
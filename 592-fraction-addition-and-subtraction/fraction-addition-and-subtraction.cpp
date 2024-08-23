class Solution {
public:
    using int2=pair<int, int>;
    void print(auto& f){
        for(auto& [x, y]: f) cout<<"("<<x<<","<<y<<")";
        cout<<endl;
    }

    vector<int2> convert(string& expression){
        vector<int2> fraction;
        stringstream ss(expression);
        char op;
        int num, denom;

        while(ss>>num>>op>>denom){
            fraction.emplace_back(num, denom);
        }

        return fraction;
    }
    int2 add(int2& x, int2& y){
        auto [xp, xq]=x;
        auto [yp, yq]=y;
        long long q=xq*yq;
        long long p=xp*yq+xq*yp;
        long long g=gcd(p, q);
        return {p/g, q/g};
    }
    
    string fractionAddition(string& expression) {
        auto fraction=convert(expression);
    //    print(fraction);
        int fz=fraction.size();
        int2 ans={0, 1};
        for(auto& f: fraction){
            ans=add(ans, f);
        }
        string s=to_string(ans.first)+"/"+to_string(ans.second);
        return s;
    }
};

auto init=[](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(0);
}();
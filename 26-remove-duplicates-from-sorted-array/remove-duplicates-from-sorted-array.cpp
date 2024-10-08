class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int i=1;
        int n = nums.size();
        for(int j=1; j<n; j++){
            if(nums[j]!= nums[i-1]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
auto init=[](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(0);
}();
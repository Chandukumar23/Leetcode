class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        int first=1,second=1;
        for(int i=2;i<=n;i++){
           int  ways=first+second;
            first=second;
            second=ways;
        }
        return second;
    }
};
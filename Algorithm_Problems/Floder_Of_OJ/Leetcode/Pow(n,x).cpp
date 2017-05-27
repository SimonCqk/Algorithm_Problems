/*
Implement pow(x, n).

直接做过不了，得用快速幂求。
*/

class Solution {
public:
    double myPow(double x, int n) {
        int pow=n;
        if(n>0){
        double ans=1;
        while(pow){
            if(pow%2){
                ans *=x;
            }
            pow /=2;
            x*=x;
        }
        return ans;
    }
    else if(n<0){
        double ans=1;
        while(pow){
            if(pow%2){
                ans *=1/x;
            }
            pow /=2;
            x*=x;
        }
        return ans;
    }
    else return 1.0;
    }
};

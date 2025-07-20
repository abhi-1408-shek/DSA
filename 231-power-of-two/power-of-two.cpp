class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0; i<31;i++){
            int r = pow(2,i);
            if(r == n){
                return true;
            }
        }
            return false;
    }
};
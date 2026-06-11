package Beginner20Java;

public class isPowerOfThree_326 {
    class Solution {
        public boolean isPowerOfThree(int n) {
            if(n==1||n==3){
                return true;
            }
            if(n<=0||n%3!=0){
                return false;
            }
            while(n>1){
                if(n%3!=0){
                    return false;
                }

                n /= 3;
            }

            return true;
        }
    }
}

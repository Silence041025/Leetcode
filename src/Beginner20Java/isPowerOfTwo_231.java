package Beginner20Java;

public class isPowerOfTwo_231 {
    class Solution {
        public boolean isPowerOfTwo(int n) {
            if(n==0){
                return false;
            }
            if(n==1||n==2){
                return true;
            }
            if(n%2!=0){
                return false;
            }
            if(n<0){
                return false;
            }

            while(n>2){
                if(n%2!=0){
                    return false;
                }

                n /= 2;
            }

            return true;
        }
    }
}

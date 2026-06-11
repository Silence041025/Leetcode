package Beginner20Java;

public class isUgly_263 {

    class Solution {
        public boolean isUgly(int n) {
            if(n<=0){
                return false;
            }

            boolean canDivide = true;
            while(canDivide){
                canDivide = false;
                if(n%2==0){
                    n /= 2;
                    canDivide = true;
                } else if (n%3==0) {
                    n /= 3;
                    canDivide = true;
                } else if (n%5==0) {
                    n /= 5;
                    canDivide = true;
                }
            }

            return n == 1;
        }
    }

}

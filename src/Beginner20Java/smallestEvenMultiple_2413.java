package Beginner20Java;

public class smallestEvenMultiple_2413 {

    class Solution {
        public int smallestEvenMultiple(int n) {
            if(n%2==0){
                return n;
            }else{
                return 2*n;
            }
        }
    }

}

package Beginner20Java;

public class xorOperation_1486 {
    class Solution {
        public int xorOperation(int n, int start) {
            int result = start;
            start += 2;
            for(int i=0;i<n-1;i++){
                result ^= start;
                start += 2;
            }

            return result;
        }
    }
}

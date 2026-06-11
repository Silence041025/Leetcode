package Beginner20Java;

public class subtractProductAndSum_1281 {
    class Solution {
        public int subtractProductAndSum(int n) {
            int addResult = 0;
            int mulResult = 1;

            while(n!=0){
                addResult += n%10;
                mulResult *= n%10;
                n /= 10;
            }

            return mulResult - addResult;
        }
    }
}

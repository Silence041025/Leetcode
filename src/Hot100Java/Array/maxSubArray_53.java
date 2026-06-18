package Hot100Java.Array;

import java.util.ArrayList;
import java.util.Collections;

public class maxSubArray_53 {

    class Solution {
        public int maxSubArray(int[] nums) {
            ArrayList<Integer> dp = new ArrayList<>(Collections.nCopies(nums.length,0));
            dp.set(0,nums[0]);
            int result = dp.get(0);
            for(int i=1;i<nums.length;i++){
                dp.set(i,Math.max(dp.get(i-1)+nums[i],nums[i]));
                result = Math.max(result,dp.get(i));
            }

            return result;
        }
    }

}

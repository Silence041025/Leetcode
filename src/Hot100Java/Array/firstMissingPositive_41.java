package Hot100Java.Array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class firstMissingPositive_41 {

    class Solution {
        public int firstMissingPositive(int[] nums) {
            HashSet<Integer> map = new HashSet<>();
            int result = 1;
            for(int i=0;i<nums.length;i++){
                if(nums[i]<=0){
                    continue;
                }
                map.add(nums[i]);
                while(map.contains(result)){
                    result++;
                }
            }

            return result;
        }
    }

}

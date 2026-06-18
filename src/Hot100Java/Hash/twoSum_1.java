package Hot100Java.Hash;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class twoSum_1 {

    class Solution {
        public int[] twoSum(int[] nums, int target) {
            List<Integer> result = new ArrayList<>();
            HashMap<Integer, Integer> hashMap = new HashMap<>();

            for(int i=0;i<nums.length;i++){
                if(hashMap.containsKey(target-nums[i])){
                    result.add(hashMap.get(target-nums[i]));
                    result.add(i);
                    break;
                }
                hashMap.put(nums[i], i);
            }

            return result.stream().mapToInt(i -> i).toArray();
        }
    }


}

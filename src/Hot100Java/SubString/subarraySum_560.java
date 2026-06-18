package Hot100Java.SubString;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class subarraySum_560 {

//    class Solution {
//        public int subarraySum(int[] nums, int k) {
//            int result = 0;
//            ArrayList<Integer> prefixSum = new ArrayList<>(Collections.nCopies(nums.length,0));
//            for(int l=0;l<prefixSum.size();l++){
//                int sum = 0;
//                for(int r=l;r<prefixSum.size();r++){
//                    sum += nums[r];
//                    if(sum==k){
//                        result++;
//                    }
//                }
//            }
//
//            return result;
//        }
//    }

    class Solution {
        public int subarraySum(int[] nums, int k) {
            int result = 0;
            int prefixSum = 0;
            HashMap<Integer, Integer> map = new HashMap<>();
            //重要！放入一个prefixSumL = 0,可以使prefixSumR就正好=k的情况收到
            map.put(0,1);
            for(int r=0;r<nums.length;r++){
                prefixSum += nums[r];
                //prefixSumR - prefixSumL = k
                //then find if there has k - prefixSumR(equal2 prefixSumL)
                if(map.containsKey(prefixSum - k)){
                    result += map.get(prefixSum - k);
                }

                map.put(prefixSum, map.getOrDefault(prefixSum,0)+1);
            }

            return result;
        }
    }

}

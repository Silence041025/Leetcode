package Hot100Java.DoublePointer;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class threeSum_15 {

    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> result = new ArrayList<>();
            Arrays.sort(nums);
            for(int i=0;i< nums.length;i++){
                if(i>0&&nums[i]==nums[i-1]){
                    continue;
                }
                int left = i+1;
                int right = nums.length-1;
                while(left<right){
                    if(nums[i]+nums[left]+nums[right]==0){
                        while(left<right&&nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right&&nums[right]==nums[right-1]){
                            right--;
                        }
                        List<Integer> integers = new ArrayList<>();
                        integers.add(nums[i]);
                        integers.add(nums[left]);
                        integers.add(nums[right]);
                        result.add(integers);
                        left++;
                        right--;
                    }
                    else if(nums[i]+nums[left]+nums[right]<0){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
            return result;
        }
    }

}

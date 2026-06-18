package Hot100Java.DoublePointer;

import java.util.Arrays;

public class moveZeroes_283 {

//    class Solution {
//        public void moveZeroes(int[] nums) {
//
//            for(int left=0;left<nums.length;left++){
//                if(nums[left]==0){
//                    int right = left+1;
//                    while (right<nums.length&&nums[right]==0){
//                        right++;
//                    }
//                    if(right== nums.length){
//                        break;
//                    }
//                    int temp = nums[right];
//                    nums[right] = nums[left];
//                    nums[left] = temp;
//                }
//
//            }
//        }
//    }

    class Solution {
        public void moveZeroes(int[] nums) {
            int left = 0;
            for(int right=0;right<nums.length;right++){
                if(nums[right]!=0){
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    left++;
                }
            }
        }
    }
}

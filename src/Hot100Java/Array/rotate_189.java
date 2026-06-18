package Hot100Java.Array;

import java.util.Arrays;

public class rotate_189 {

    class Solution {
        static void reverse(int[] arr,int left,int right){
            if(left<0||right>= arr.length){
                return;
            }
            while(left<right){
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }

        public void rotate(int[] nums, int k) {
            k %= nums.length;
            reverse(nums,0,nums.length-1);
            reverse(nums,0,k-1);
            reverse(nums,k,nums.length-1);
        }
    }

}

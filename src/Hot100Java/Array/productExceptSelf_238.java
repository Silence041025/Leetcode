package Hot100Java.Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class productExceptSelf_238 {

    class Solution {
        public int[] productExceptSelf(int[] nums) {
            ArrayList<Integer> preProLeft = new ArrayList<>(Collections.nCopies(nums.length,1));
            ArrayList<Integer> preProRight = new ArrayList<>(Collections.nCopies(nums.length,1));
            ArrayList<Integer> answer = new ArrayList<>(Collections.nCopies(nums.length,1));
            for(int i=1;i<nums.length;i++){
                preProLeft.set(i,preProLeft.get(i-1) * nums[i-1]);
            }

            for(int i=nums.length-2;i>=0;i--){
                preProRight.set(i,preProRight.get(i+1) * nums[i+1]);
            }

            for(int i=0;i<answer.size();i++){
                answer.set(i,preProLeft.get(i)*preProRight.get(i));
            }

            return answer.stream().mapToInt(i->i).toArray();
        }
    }

}

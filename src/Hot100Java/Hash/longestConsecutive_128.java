package Hot100Java.Hash;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class longestConsecutive_128 {

//    class Solution {
//        public int longestConsecutive(int[] nums) {
//            int result = 0;
//            HashMap<Integer, Integer> hashMap = new HashMap<>();
//            for(int i=0;i<nums.length;i++){
//                if(hashMap.containsKey(nums[i])){
//                    continue;
//                }
//                int leftLength = hashMap.getOrDefault(nums[i]-1,0);
//                int rightLength = hashMap.getOrDefault(nums[i]+1,0);
//                int newLength = leftLength + 1 + rightLength;
//
//                hashMap.put(nums[i]-leftLength,newLength);
//                hashMap.put(nums[i]+rightLength,newLength);
//                hashMap.put(nums[i],newLength);
//                result = Math.max(result,newLength);
//            }
//
//            return result;
//        }
//    }

    class Solution {
        public int longestConsecutive(int[] nums) {
            HashSet<Integer> hashSet = new HashSet<>();
            for(int num:nums){
                hashSet.add(num);
            }

            int result = 0;
            for(int num:hashSet){
                if(!hashSet.contains(num-1)){
                    int currentNum = num;
                    int currentStreak = 1;
                    while(hashSet.contains(currentNum+1)){
                        currentNum++;
                        currentStreak++;
                    }
                    result = Math.max(result,currentStreak);
                }
            }

            return result;
        }
    }
}



package Hot100Java.SubString;

import java.util.ArrayDeque;
import java.util.Deque;

public class maxSlidingWindow_239 {

    class Solution {
        static void push(Deque<Integer> deque,int val){
            while(!deque.isEmpty()&&deque.getLast() < val){
                deque.pollLast();
            }
            deque.addLast(val);
        }

        static void pop(Deque<Integer> deque,int val){
            if(deque.getFirst()==val){
                deque.pollFirst();
            }
        }

        static int getMaxValue(Deque<Integer> deque){
            return deque.getFirst();
        }

        public int[] maxSlidingWindow(int[] nums, int k) {
            int[] result = new int[nums.length-k+1];
            Deque<Integer> deque = new ArrayDeque<>();
            for(int i=0;i<k;i++){
                push(deque,nums[i]);
            }
            result[0] = getMaxValue(deque);

            for(int i=1;i<nums.length-k+1;i++){
                pop(deque,nums[i-1]);
                push(deque,nums[i+k-1]);
                result[i] = getMaxValue(deque);
            }

            return result;
        }
    }


}

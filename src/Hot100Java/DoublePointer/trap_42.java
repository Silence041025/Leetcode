package Hot100Java.DoublePointer;

import java.util.Stack;

public class trap_42 {

    class Solution {
        public int trap(int[] height) {
            int result = 0;
            Stack<Integer> stk = new Stack<Integer>();
            // right：i
            //  mid : .top()
            // left : .pop() , .top()
            for(int i=0;i<height.length;i++){
                while(!stk.empty()&&height[i]>height[stk.peek()]){
                    int mid = stk.peek();
                    stk.pop();
                    if(!stk.empty()){
                        int left = stk.peek();
                        int width = i - left - 1;
                        int h = Math.min(height[left],height[i]) - height[mid];
                        result += width*h;
                    }
                }
                stk.push(i);
            }

            return result;
        }
    }

}

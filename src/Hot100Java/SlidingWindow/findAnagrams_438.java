package Hot100Java.SlidingWindow;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class findAnagrams_438 {

    class Solution {
        public List<Integer> findAnagrams(String s, String p) {
            if(p.length()>s.length()){
                return new ArrayList<>();
            }
            List<Integer> result = new ArrayList<>();
            char[] pattern = p.toCharArray();
            char[] str = s.toCharArray();
            int[] patternMap = new int[256];
            for(int i=0;i<pattern.length;i++){
                patternMap[pattern[i]]++;
            }
            int left = 0;
            int right = p.length() - 1;
            int match = 0;
            int[] windowMap = new int[256];
            for(int i=left;i<=right;i++){
                windowMap[str[i]]++;
                if(patternMap[str[i]]!=0&&windowMap[str[i]]<=patternMap[str[i]]){
                    match++;
                }
            }
            //while会进不去，初始窗口单独判断
            if(match==p.length()){
                result.add(left);
            }

            //right++完了，会有判断，边界往左错位一个
            while(right<str.length-1){
                //是匹配字符，而且不是多余的，则匹配度match--
                if(patternMap[str[left]]!=0&&
                windowMap[str[left]]<=patternMap[str[left]]){
                    match--;
                }
                windowMap[str[left]]--;
                left++;

                right++;
                windowMap[str[right]]++;
                //是匹配字符，而且不是多余的，则匹配度match++
                if(patternMap[str[right]]!=0&&
                windowMap[str[right]]<=patternMap[str[right]]){
                    match++;
                }
                if(match==p.length()){
                    result.add(left);
                }
            }

            return result;
        }
    }

}

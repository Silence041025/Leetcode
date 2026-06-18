package Hot100Java.SlidingWindow;

public class lengthOfLongestSubstring_3 {

    class Solution {
        public int lengthOfLongestSubstring(String s) {
            if(s.length()==0){
                return 0;
            }
            char[] str = s.toCharArray();
            int result = 1;
            int len = 1;
            int left = 0;
            char[] map = new char[256];
            for(int right=0;right<str.length;right++){
                char c = str[right];
                map[c]++;
                while (map[c]>1){
                    map[str[left]]--;
                    left++;
                }

                result = Math.max(result,right-left+1);
            }

            return result;
        }
    }

}

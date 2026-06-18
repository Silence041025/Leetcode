package Hot100Java.SubString;

public class minWindow_76 {

    class Solution {
        public String minWindow(String s, String t) {
            int[] tMap = new int[256];
            int[] windowMap = new int[256];
            char[] tStr = t.toCharArray();
            char[] sStr = s.toCharArray();
            int match = 0;
            String result = "";
            int left = 0;
            int right = 0;
            //Init tMap
            for(int i=0;i<tStr.length;i++){
                char c = tStr[i];
                tMap[c]++;
            }

            while(right<s.length()){
                char cr = sStr[right];
                //right往右探索直到结束/符合条件
                //[right]是匹配字符，且不是多余的
                if(tMap[cr]>0&&windowMap[cr]<tMap[cr]){
                    //匹配度增加
                    match++;
                }
                windowMap[cr]++;
                right++;

                //left往右找更短解
                while(match==t.length()){
                    char cl = sStr[left];
                    if(result==""||result.length() > right-left){
                        //right先往右走了一下，所以长度不用+1
                        result = s.substring(left,right);
                    }
                    //[left]是匹配字符，而且不是多余的
                    if(tMap[cl]>0&&windowMap[cl] <= tMap[cl]){
                        match--;
                    }
                    left++;
                    windowMap[cl]--;
                }
            }

            return result;
        }
    }

}

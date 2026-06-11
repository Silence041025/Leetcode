package Beginner20Java;

public class toLowerCase_709 {
    class Solution {
        public String toLowerCase(String s) {

            StringBuilder result = new StringBuilder().append(s);
            for(int i=0;i<s.length();i++){
                char c = result.charAt(i);
                if(c>='A'&&c<='Z'){
                    result.setCharAt(i,(char)(c+32));
                }
            }

            return result.toString();
        }
    }
}

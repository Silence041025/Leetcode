package Hot100Java.Hash;

import java.util.*;

public class groupAnagrams_49 {

    class Solution {
        public List<List<String>> groupAnagrams(String[] strs) {
            HashMap<String, List<String>> hashMap = new HashMap<>();
            for(int i=0;i<strs.length;i++){
                char[] temp = strs[i].toCharArray();
                Arrays.sort(temp);
                String key = new String(temp);
                if(hashMap.containsKey(key)){
                    hashMap.get(key).add(strs[i]);
                }else{
                    List<String> values = new ArrayList<>();
                    values.add(strs[i]);
                    hashMap.put(key,values);
                }
            }

            List<List<String>> result = new ArrayList<>(hashMap.values());
            return result;
        }
    }


}

package Hot100Java.Array;

import java.util.ArrayList;
import java.util.Arrays;

public class merge_56 {

    class Solution {
        public int[][] merge(int[][] intervals) {
            ArrayList<int[]> result = new ArrayList<>();
            Arrays.sort(intervals,(a,b)->{
                return a[0] - b[0];
            });
            result.add(intervals[0]);
            int resultEndIndex = 0;
            for(int i=1;i<intervals.length;i++){
                if(intervals[i][0] <= result.get(resultEndIndex)[1]){
                    result.get(resultEndIndex)[1] = Math.max(result.get(resultEndIndex)[1],intervals[i][1]);
                }else{
                    resultEndIndex++;
                    result.add(intervals[i]);
                }
            }

            return result.toArray(new int[result.size()][]);
        }
    }

}

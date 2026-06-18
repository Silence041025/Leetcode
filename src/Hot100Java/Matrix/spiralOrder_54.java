package Hot100Java.Matrix;

import java.util.ArrayList;
import java.util.List;

public class spiralOrder_54 {

    class Solution {
        public List<Integer> spiralOrder(int[][] matrix) {
            ArrayList<Integer> result = new ArrayList<>();
            int colStart = 0;
            int colEnd = matrix[0].length-1;
            int rowStart = 0;
            int rowEnd = matrix.length-1;

            while(rowStart<=rowEnd&&colStart<=colEnd){
                for(int j=colStart;j<=colEnd;j++){
                    result.add(matrix[rowStart][j]);
                }
                rowStart++;

                for(int i=rowStart;i<=rowEnd;i++){
                    result.add(matrix[i][colEnd]);
                }
                colEnd--;

                if(rowStart<=rowEnd&&colStart<=colEnd){
                    for(int j=colEnd;j>=colStart;j--){
                        result.add(matrix[rowEnd][j]);
                    }
                    rowEnd--;
                }

                if(rowStart<=rowEnd&&colStart<=colEnd){
                    for(int i=rowEnd;i>=rowStart;i--){
                        result.add(matrix[i][colStart]);
                    }
                    colStart++;
                }
            }

            return result;
        }
    }

}

package Hot100Java.Matrix;

import java.util.Arrays;

public class setZeroes_73 {

    class Solution {
        public void setZeroes(int[][] matrix) {
            boolean[] rowZeros = new boolean[matrix.length];
            Arrays.fill(rowZeros,false);
            boolean[] colZeros = new boolean[matrix[0].length];
            Arrays.fill(colZeros,false);
            for(int i=0;i< matrix.length;i++){
                for(int j=0;j<matrix[0].length;j++){
                    if(matrix[i][j]==0){
                        rowZeros[i] = true;
                        colZeros[j] = true;
                    }
                }
            }

            for(int i=0;i<matrix.length;i++){
                for(int j=0;j<matrix[0].length;j++){
                    if(rowZeros[i]||colZeros[j]){
                        matrix[i][j] = 0;
                    }
                }
            }

        }
    }

}

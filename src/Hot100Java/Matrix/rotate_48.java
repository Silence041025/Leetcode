package Hot100Java.Matrix;

public class rotate_48 {

    class Solution {
        public void rotate(int[][] matrix) {
            //先Transpose，再左右Reverse

            for(int i=0;i<matrix.length;i++){
                for(int j=i+1;j<matrix[0].length;j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }

            for(int j=0;j<matrix[0].length/2;j++){
                for(int i=0;i<matrix.length;i++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][matrix[0].length-j-1];
                    matrix[i][matrix[0].length-j-1] = temp;
                }
            }
        }
    }

}

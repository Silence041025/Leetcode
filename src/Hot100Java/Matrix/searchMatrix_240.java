package Hot100Java.Matrix;

public class searchMatrix_240 {

    class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            //从右上角往左下看，这是个BST啊
            int i=0;
            int j=matrix[0].length-1;
            while(i>=0&&i<matrix.length&&j>=0&&j<matrix[0].length){
                if(matrix[i][j]==target){
                    return true;
                }else if(matrix[i][j]>target){
                    j--;
                }else{
                    i++;
                }
            }

            return false;
        }
    }

}

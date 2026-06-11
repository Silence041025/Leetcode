package Beginner20Java;

public class checkTree_2236 {

    class Solution {
        public boolean checkTree(TreeNode root) {
            return root.val == root.left.val + root.right.val;
        }
    }

}

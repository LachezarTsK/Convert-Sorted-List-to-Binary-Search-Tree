
public class Solution {

    public TreeNode sortedListToBST(ListNode head) {
        int totalNodes = countNodes(head);
        int[] values = new int[totalNodes];
        fillArrayValues(head, values);
        TreeNode root = null;
        return convertSortedArrayToBST(root, values, 0, values.length - 1);
    }

    private TreeNode convertSortedArrayToBST(TreeNode root, int[] values, int lower, int upper) {
        if (lower > upper) {
            return null;
        }

        int middle = lower + (upper - lower) / 2;
        root = new TreeNode(values[middle]);
        root.left = convertSortedArrayToBST(root.left, values, lower, middle - 1);
        root.right = convertSortedArrayToBST(root.right, values, middle + 1, upper);

        return root;
    }

    private int countNodes(ListNode head) {
        int totalNodes = 0;
        ListNode current = head;
        while (current != null) {
            current = current.next;
            ++totalNodes;
        }
        return totalNodes;
    }

    private void fillArrayValues(ListNode head, int[] values) {
        int index = 0;
        ListNode current = head;
        while (current != null) {
            values[index] = current.val;
            current = current.next;
            ++index;
        }
    }
}

/*
Class ListNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

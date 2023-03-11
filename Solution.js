
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
var sortedListToBST = function (head) {
    let totalNodes = countNodes(head);
    const values = new Array(totalNodes);
    fillArrayValues(head, values);
    let root = null;
    return convertSortedArrayToBST(root, values, 0, values.length - 1);
};

/**
 * @param {TreeNode} root
 * @param {number[]} values
 * @param {number} lower
 * @param {number} upper 
 * @return {TreeNode}
 */
function convertSortedArrayToBST(root, values, lower, upper) {
    if (lower > upper) {
        return null;
    }

    let middle = lower + Math.floor((upper - lower) / 2);
    root = new TreeNode(values[middle]);
    root.left = convertSortedArrayToBST(root.left, values, lower, middle - 1);
    root.right = convertSortedArrayToBST(root.right, values, middle + 1, upper);

    return root;
}

/**
 * @param {TreeNode} head
 * @return {number}  
 */
function countNodes(head) {
    let totalNodes = 0;
    let current = head;
    while (current !== null) {
        current = current.next;
        ++totalNodes;
    }
    return totalNodes;
}

/**
 * @param {TreeNode} head
 * @param {number[]} values 
 * @return {number}  
 */
function fillArrayValues(head, values) {
    let index = 0;
    let current = head;
    while (current !== null) {
        values[index] = current.val;
        current = current.next;
        ++index;
    }
}

/*
 Function ListNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

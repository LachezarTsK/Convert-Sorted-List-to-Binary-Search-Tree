
#include <vector>
using namespace std;

/*
Struct ListNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    TreeNode* sortedListToBST(ListNode* head)const {
        size_t totalNodes = countNodes(head);
        vector<int>values(totalNodes);
        fillArrayValues(head, values);
        TreeNode* root = nullptr;
        return convertSortedArrayToBST(root, values, 0, values.size() - 1);
    }

private:
    TreeNode* convertSortedArrayToBST(TreeNode* root, vector<int>& values, size_t lower, size_t upper) const {
        if (upper == variant_npos || lower > upper) {
            return nullptr;
        }

        size_t middle = lower + (upper - lower) / 2;
        root = new TreeNode(values[middle]);
        root->left = convertSortedArrayToBST(root->left, values, lower, middle - 1);
        root->right = convertSortedArrayToBST(root->right, values, middle + 1, upper);

        return root;
    }

    size_t countNodes(ListNode* head) const {
        size_t totalNodes = 0;
        ListNode* current = head;
        while (current != nullptr) {
            current = current->next;
            ++totalNodes;
        }
        return totalNodes;
    }

    void fillArrayValues(ListNode* head, vector<int>& values) const {
        size_t index = 0;
        ListNode* current = head;
        while (current != nullptr) {
            values[index] = current->val;
            current = current->next;
            ++index;
        }
    }
};

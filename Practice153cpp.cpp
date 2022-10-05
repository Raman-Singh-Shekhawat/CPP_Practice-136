/*154. Next larger: Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *nextLargest = NULL;
    if (root->data > x)
    {
        nextLargest = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);

        if (nextLargest == NULL)
        {
            nextLargest = smallAns;
        }
        else if (smallAns != NULL && smallAns->data < nextLargest->data) // No need to check if smallAns -> data > x.. its already checked
        {
            nextLargest = smallAns;
        }
    }
    return nextLargest;
}
struct TreeNode {
  public:
    int data;
    TreeNode *left;
    TreeNode *right;
};


TreeNode* newTreeNode(int d);
TreeNode* insert(TreeNode *root, int data);
TreeNode* findSuccessor(TreeNode* node);
TreeNode* deleteNode(TreeNode* root, int key);

void inorder(TreeNode *node);

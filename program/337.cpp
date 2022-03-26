int rob(TreeNode* root) {
    if(root == NULL) return 0;
    else if(root->val<0) return -root->val;
    int profitCur=0, profitNext=0;
    // 偷当前所获得的收益
    profitCur += root->val;
    if(root->left){
        profitNext += rob(root->left);
        profitCur += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right){
        profitNext += rob(root->right);
        profitCur += rob(root->right->left) + rob(root->right->right);
    }
    root->val = -max(profitCur, profitNext);
    return -root->val;
}

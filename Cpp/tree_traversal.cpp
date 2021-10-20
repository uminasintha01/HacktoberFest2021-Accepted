#include<bits/stdc++.h>
using namespace std;
/* 
    Binary Search Tree:-
        The left subtree of a node contains  only nodes with keys lesser than the node’s key.
        The right subtree of a node contains only nodes with keys greater than the node’s key.
        The left and right subtree each must also be a binary search tree. 
        There must be no duplicate nodes.
*/

// object of this class represent a node in the tree

class TreeNode {

    public:
        int val;
        TreeNode *left,*right;

        //constructor 
        TreeNode(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode *insert(TreeNode *root, int key) {

    // if root is null then return the new node 
    if(!root) return new TreeNode(key);

    // if the new key is less than root node then it will add in the left subtree.
    if(key < root->val) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

// inorder traversal of the BST always print node values in sorted order
void inorder(TreeNode *root) {

    if(!root) {
        return ;
    }
    inorder(root->left);
    // you can store these values in an array as well
    cout<<root->val<<" ";
    inorder(root->right);

}

void preorder(TreeNode *root) {

    if(!root) {
        return ;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(TreeNode *root) {

    if(!root) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";

}

void levelOrder(TreeNode *root) {

    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

void zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result ;
        if(root == NULL) return;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        while(!q.empty()) {
            
            int size = q.size();
            vector<int> value;

            //no of node present at a level = size;
            //pop one by one and push their child.
            while(size --) {
                
                TreeNode *node  = q.front();
                value.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node ->right != NULL) q.push(node->right);
            }
            result.push_back(value);
        }
        for(int i = 0; i< result.size(); i++ ) {

            //reverse odd indexed array
            if(i%2 ==1 ) {
                reverse(result[i].begin(), result[i].end());
            }
        }

        for(int i = 0; i< result.size(); i++) {

            for(int j = 0; j< result[i].size(); j++) {
                cout<<result[i][j]<<" ";
            }
        }
}

int main() {

    TreeNode* root = NULL;

    int arr[9] = {20, 15, 40, 9, 18, 35, 60, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    cout<<"Inorder- ";
    inorder(root);
    cout<<endl;


    cout<<"preorder- ";
    preorder(root);
    cout<<endl;


    cout<<"postorder- ";
    postorder(root);
    cout<<endl;

    cout<<"level-order- ";
    levelOrder(root);
    cout<<endl;

    cout<<"zigzag-level-order- ";
    zigzagLevelOrder(root);
    cout<<endl;




}
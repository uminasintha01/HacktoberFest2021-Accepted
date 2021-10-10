#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Tnode{
    int data;
    struct Tnode* left;
    struct Tnode* right;
} tnode;

tnode* getTNode(int val){
    tnode* temp = (tnode *)malloc(sizeof(tnode));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int max(int a,int b){
    return( a>b? a:b);
}

void print_preorder(tnode* head){
    if(head == NULL)    return;

    printf("%d ",head->data);
    print_preorder(head->left);
    print_preorder(head->right);
}

void print_postorder(tnode* head){
    if(head == NULL)    return;

    print_postorder(head->left);
    print_postorder(head->right);
    printf("%d ",head->data);
}

void print_inorder(tnode* head){
    if(head == NULL)    return;

    print_inorder(head->left);
    printf("%d ",head->data);
    print_inorder(head->right);
}

int search_tnode(int in[],int st, int en,int cur){
    
    for(int i = st ; i <= en ; i++){
        if(in[i] == cur)    return i;
    }

    return -1;
}

tnode* buildTree_pre(int pre[] , int in[] , int st , int en){
    static int id = 0;

    if(st > en) return NULL;

    int cur = pre[id];
    id++;

    tnode* temp = getTNode(cur);
    int pos = search_tnode(in,st,en,cur);

    if(st == en)    return temp;


    temp->left = buildTree_pre(pre,in,st,pos-1);
    temp->right = buildTree_pre(pre,in,pos+1,en);

    return temp;
}

tnode* buildTree_post(int post[],int in[],int st,int en){
    static int idx = 4;

    if(st > en) return NULL;

    int cur = post[idx];
    idx--;

    tnode* temp = getTNode(cur);
    int pos = search_tnode(in,st,en,cur);

    if(st == en)    return temp;

    temp->right = buildTree_post(post,in,pos+1,en);
    temp->left = buildTree_post(post,in,st,pos-1);

    return temp;
}

tnode* insert_BST(tnode* root,int val){

    if(root == NULL){
        tnode* temp = (tnode *)malloc(sizeof(tnode));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if(val > root->data){
        root->right = insert_BST(root->right,val);
    }
    else{
        root->left = insert_BST(root->left,val);
    }

    return root;
}

int search_BST(tnode* root , int val){

    if(root == NULL)    return -1;

    if(root->data == val){
        return 1;
    }
    else if(root->data < val){
        return search_BST(root->right,val);
    }
    else{
        return search_BST(root->left,val);
    }
}

tnode* inorder_succ(tnode* root){

    tnode* cur = root;

    while(cur && cur->left != NULL){
        cur = cur->left;
    }

    return cur;
}

tnode* deleteBST(tnode* root , int val){
    
    if(root->data < val){
        root->right = deleteBST(root->right,val);
    }
    else if(root->data > val){
        root->left = deleteBST(root->left,val);
    }
    else{
        if(root->left == NULL){
            tnode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            tnode* temp = root->left;
            free(root);
            return temp;
        }

        tnode* temp = inorder_succ(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }

    return root;
}

int test_Full(tnode* root){
    if(root == NULL)    return 1;

    if ((root->left == NULL) && (root->right == NULL))  return 1;

    if((root->left != NULL) && (root->right != NULL)){
        return (test_Full(root->left) && test_Full(root->right));
    }
    
    return 0;
}

int count_Nodes(tnode* root){
    if(root == NULL)    return 0;

    return(1 + count_Nodes(root->left) + count_Nodes(root->right));
}

int check_Complete(tnode* root,int idx,int num){
    if(root == NULL)    return 1;

    if(idx >= num)  return 0;

    return(check_Complete(root->left,2*idx +1,num) && check_Complete(root->right,2*idx + 2,num));
}

int treeDepth(tnode* root){
    if(root == NULL)    return 0;

    return 1 + max(treeDepth(root->left),treeDepth(root->right));
}

int check_Balanced(tnode* root){
    if(root == NULL)    return 1;
    
    int h1 = treeDepth(root->left);
    int h2 = treeDepth(root->right);
    int diff = abs(h1-h2);

    if(diff <= 1){
        return(check_Balanced(root->left) && check_Balanced(root->right));
    }

    return 0;
}

int main(){

    tnode* root = getTNode(1);
    root->left = getTNode(2);
    root->right = getTNode(3);
    root->left->right = getTNode(5);
    root->left->left = getTNode(4);
    root->left->left->left = getTNode(4);
    //root->right->left = getTNode(8);
    // root->right->right = getTNode(6);
    // root->right->right->right = getTNode(7);
    // root->right->right->right->right = getTNode(4);

    int n = count_Nodes(root);

    printf("%d\n",check_Balanced(root));

    return 0;
}
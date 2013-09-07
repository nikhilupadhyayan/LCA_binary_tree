#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
}Node;
/*
Node* find_LCA_bst(Node* root,int val1,int va2)
{
//to check condition fot non existence of a val, send a pointer to interger(value 0) as parameter to this function .and increase it whenever val is found.
//After whole function compeleted , if the variabel value is 2 , it mesans both value found.
    if(!root)
    return NULL;
    if(val1>root->data&&val2>root->data)
        return find_LCA_bst(root->right,val1,val2);
    if(val1<root->data&&val2<root->data)
        return find_LCA_bst(root->left,val1,val2);
    if( minimum(val1,val2) < root->data && maximum(val1,val2) > root->data )
        return root;
    if(val1==root->data||val2==root->data)
        return root;
}
*/
Node* find_LCA(Node* root,int val1,int val2,Node** util)
{
    Node* left_temp=NULL;
    Node* right_temp=NULL;
    if(root->left)
        left_temp=find_LCA(root->left,val1,val2,util);
    if(root->right)
        right_temp=find_LCA(root->right,val1,val2,util);
    if(root->data==val1||root->data==val2) //if one of val1 or val2 found,then return it.
        {

            if(left_temp&&!right_temp)  //this condition checks if LCA is either of val1 or val2.In which case this itself becomes the LCA.
                right_temp=root;
            else if(!left_temp&&right_temp)
                left_temp=root;
            else
                return root;
        }
    if(left_temp!=NULL&&right_temp!=NULL)//if val1 and va2 are on either side of current node,then current node is LCA
    {
        *util=root;
        return NULL;
    }
    else        //else return either of left or right.If both null,then Null is returned
        return left_temp?left_temp:right_temp;

}
int LCA(Node* root,int val1,int val2)
{
    Node* LCA_temp=NULL;
    find_LCA(root, val1, val2,&LCA_temp);
    if(LCA_temp)
        return LCA_temp->data;
    else
        return -1;
}
Node* new_node(int val)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
Node* create_binary_tree(Node* root)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=1;
    temp->left=temp->right=NULL;
    root=temp;
    root->left=new_node(2);
    root->right=new_node(3);
    root->left->left=new_node(4);
    root->left->right=new_node(5);
    root->right->left=new_node(6);
    root->right->right=new_node(7);
    return root;
}
int main()
{
    Node* root=NULL;
    root=create_binary_tree(root);
    printf("%d",LCA(root,1,7));//observe that here, 1 itself is the LCA.
}

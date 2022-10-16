// Binary Search Tree Implementation..  
// @KS.
#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* left;	
	Node* right;
	Node(int data){
		this->data=  data;
		left= right= NULL;
	}
}; 
class BinarySearchTree{
	public:
	Node* root;
	BinarySearchTree(){
		root= NULL;
	}
	
	Node* insert( Node* root, int val);
	Node* DeleteNodeInBST(Node* root,int data);
	Node* inOrderTraversal( Node* root);
	Node* preOrderTraversal( Node* root);
	Node* postOrderTraversal( Node* root);
	Node* merge( Node* r1, Node* r2);
	Node* FindMax(Node* root);
	int leafCount (Node* root);
	int treeHeight(Node *root);
};

int main (){
	BinarySearchTree tree1, tree2;
	
  	tree1.insert(tree1.root,10);
    tree1.insert(tree1.root, 8);
    tree1.insert(tree1.root, 6);
    tree1.insert(tree1.root, 9);
    tree1.insert(tree1.root, 15);
    tree1.insert(tree1.root, 14);
    tree1.insert(tree1.root, 20);
	
//	tree.DeleteNodeInBST(tree.root ,9);
 
	
	cout<<"In Order Print (left--Root--Right)"<<endl;
	tree1.inOrderTraversal(tree1.root);
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Pre Order Print (Root--left--Right)"<<endl;
	
	tree1.preOrderTraversal(tree1.root);	
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Post Order Print (left--Right--Root)"<<endl;

	tree1.postOrderTraversal(tree1.root);
	cout<<"\n\nThe total leaf node in tree are: "<< tree1.leafCount(tree1.root);
	
	cout<<"\n\nThe height of root node is : "<< tree1.treeHeight(tree1.root);
	
	// Merge .
	
	tree2.insert(tree2.root, 7);
    tree2.insert(tree2.root, 33);
	
	tree1.merge(tree2.root, tree1.root);
	cout<<"\n\nAfter Merging"<<endl;
	cout<<"In Order Print (left--Root--Right)"<<endl;
	
	tree1.inOrderTraversal(tree1.root);
	cout<<"\n\nThe total leaf node in tree are: "<< tree1.leafCount(tree1.root);
	
	cout<<"\n\nThe height of root node is : "<< tree1.treeHeight(tree1.root);
	
	return 0;
}

Node* BinarySearchTree::FindMax(Node* r){
	
	while(r->right!=NULL){
		r= r->right;
	}
	return r;
	
}

Node* BinarySearchTree::insert(Node* r, int val ){
	
 if (r==NULL)
	{
		Node* t= new Node(val);
		
		if (r==root)
		root= r=t;
		else
		r=t;
	}
	else if (r->data== val){
	cout<<"Duplicate Record  "<<val;
	}
	else if (val < r->data)
		r->left = insert(r->left , val );
	
	else if (val > r->data)
		r->right= insert( r->right,val);
return r;
}
Node * BinarySearchTree::DeleteNodeInBST(Node* root, int data)
{
	
	if(root==NULL)
	 return root;
    else if(data<root->data) 
        root->left = DeleteNodeInBST(root->left, data);
    else if (data> root->data)
        root->right = DeleteNodeInBST(root->right, data);
    else
    {
        //No child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;   
            return root;
        }
        //One child on left
        else if(root->right == NULL)
        {
            Node* temp = root;
            root= root->left;
            delete temp;
        }
        //One child on right
        else if(root->left == NULL)
        {
            Node* temp = root;
            root= root->right;
            delete temp;
        }
        //two child
        else
        {
            Node* temp = FindMax(root->left);
            root->data = temp->data;
            root->left = DeleteNodeInBST(root->left, temp->data);
        }
    }
    return root;
}


Node * BinarySearchTree::inOrderTraversal( Node* r){
	 if (r == NULL)
        return NULL;
    /* first recur on left child */
    inOrderTraversal(r->left);
    /* then print the data of node */
    cout << " "<< r->data << " -> ";
    /* now recur on right child */
    inOrderTraversal(r->right);
    
}

Node* BinarySearchTree::preOrderTraversal( Node* r){
	 if (r == NULL)
        return NULL;
    
    cout << " "<< r->data << " -> ";
    preOrderTraversal(r->left);
    preOrderTraversal(r->right);	
}
Node* BinarySearchTree::postOrderTraversal( Node* r){
	 if (r == NULL)
        return NULL;
    postOrderTraversal(r->left);
    postOrderTraversal(r->right);	
    cout << " "<< r->data << " -> ";
}

int BinarySearchTree::leafCount(Node * r){
	int static count= 0;
    if(r == NULL)
        return 0;
    else if(r->left == NULL && r->right == NULL)
        return 1;

    return count + leafCount(r->left) + leafCount(r->right);
}

int BinarySearchTree::treeHeight(Node *root)
{
	int static l_height=0;
	int static r_height=0;
    if (root == NULL)
        return -1;
    else
    {
    l_height = treeHeight(root->left);
       r_height = treeHeight(root->right);
        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
}
// This method will merge tree1 into tree2
Node * BinarySearchTree::merge( Node* r1, Node* r2){
	 if (r1 == NULL)
        return NULL;
    /* first recur on left child */
    merge(r1->left, r2);
    
    insert(r2, r1->data);
    /* now recur on right child */
    merge(r1->right, r2);
    
}

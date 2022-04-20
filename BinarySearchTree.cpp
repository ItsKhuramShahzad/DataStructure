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
	Node* FindMax( Node* root);
};

int main (){
	BinarySearchTree tree;
	
	tree.insert(tree.root, 7 );
	tree.insert(tree.root, 4 );
	tree.insert(tree.root, 8 );
	tree.insert(tree.root, 3 );
	tree.insert(tree.root, 9 );
	tree.insert(tree.root, 5 );
	tree.DeleteNodeInBST(tree.root, 7);
	tree.DeleteNodeInBST(tree.root, 8);
	
	cout<<"In Order Print (left--Root--Right)"<<endl;
	tree.inOrderTraversal(tree.root);
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Pre Order Print (Root--left--Right)"<<endl;
	
	tree.preOrderTraversal(tree.root);	
	
	cout<<"\n-----------------------"<<endl;
	cout<<"Post Order Print (left--Right--Root)"<<endl;
		tree.postOrderTraversal(tree.root);
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
		
		return r;
	}
	else if (r->data== val){
		cout<<"Duplicate Record  "<<val;
			return r;
	}
	else if (r->data < val)
		r->left = insert(r->left , val );
	
	else if (r->data> val)
		r->right= insert( r->right,val);

}
Node * BinarySearchTree::DeleteNodeInBST(Node* root, int data){
	
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
        }
        //One child 
        else if(root->right == NULL)
        {
            Node* temp = root;
            root= root->left;
            delete temp;
        }
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


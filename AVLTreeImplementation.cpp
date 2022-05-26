/* AVL Tree Implementation in C++   */
/* @KS                         */

#include<iostream>
using namespace std;

	class  node
    {
    	public:
        int data;
        node* left;
        node* right;
        int height;
        
		node (int data){
        	this->data= data;
        	left= right= NULL;
        	height =0;
        	
		}
    };
    
    
class AVLTree
{
	//private:

    
    node* root;
    void makeEmpty(node* t);
    node* insert(int x, node* t);

	// Rotation
    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleRightLeftRotate(node* &t);
    node* doubleLeftRightRotate(node* &t);
    
    
    node* findMin(node* t);
    node* findMax(node* t);
    node* remove(int x, node* t);
    int height(node* t);
    int getBalance(node* t);
    void inorder(node* t);

public:
    AVLTree()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
  	tree.insert(3);
  	tree.insert(5);
  	tree.insert(6);
  	tree.insert(7);
  
    tree.display();
}

void AVLTree::makeEmpty(node* t) {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    
node*  AVLTree::  insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node (x);
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleLeftRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleRightLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }
    
     node* AVLTree::singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* AVLTree::singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->right), t->height)+1 ;
        return u;
    }

    node* AVLTree::doubleRightLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* AVLTree::doubleLeftRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
   
    node* AVLTree::findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    node* AVLTree::findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* AVLTree::remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleRightLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleLeftRightRotate(t);
        }
        return t;
    }

    int AVLTree::height(node* t)
    {
        return ( t == NULL ? -1 : t->height);
    }

    int AVLTree::getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }
    void AVLTree::inorder(node* t)
    {
    	
        if(t == NULL)
            return;
     
        inorder(t->left);  
        inorder(t->right);
        cout << t->data << " -> ";
        
    }
    
//	void AVLTree::preorder(node* t)
//    {
//        if(t == NULL)
//            return;
//        cout << t->data << " -> ";
//        inorder(t->left);
//        inorder(t->right);
//    }


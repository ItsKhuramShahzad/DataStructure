#include <iostream>
using namespace std;
class ThreadedBST;
class Node {
    private:
        int data;
        Node *left, *right;
        bool lthread, rthread;

    public:
        // Used to assign value to a node
        Node(int data){
        	this->data= data;
        	this->left= this->right=NULL;
        	lthread = rthread = true;
        }

        // Deallocate space for Node
        ~Node(){
        	delete left;
	    	delete right;
	    	left = NULL;
	    	right = NULL;
		}
        // Will allow tree to access Nodes
        friend class ThreadedBST;
};

class ThreadedBST {
    private:
        Node *ROOT;

    public:
        // Allocates space for TBT
        ThreadedBST();

        // Deallocates TBT
        ~ThreadedBST();

        // Creates a Tree, caller for build
        void create();

        // Finds a node with given value & returns its parent also
        pair<Node*, Node*> search(int data);
 
        // Recursively forms a TBT
        Node* insertIntoTree(int data);

        // Finds inorder successor via left & right child threads
        Node* inSucc(Node*);

        // Finds inorder predecessor via left & right child threads
        Node* inPred(Node*);

        // Deletes a node with no child
        Node* deleteNoChild(Node *, Node *, Node*);

        // Deletes a node with one child
        Node* deleteOneChild(Node*, Node*, Node*);

        // Deletes a node with two child
        Node* deleteTwoChild(Node*, Node*, Node*);

        // Deletes a node from tree
        void remove(int data);

        // Prints nodes in inorder fashion
        void inorder();

        // Prints nodes in preorder fashion
        void preorder();

        // Prints the leaf nodes of a tree
        void leafly();
};
ThreadedBST  :: ThreadedBST() {
    ROOT = NULL;
}

ThreadedBST  :: ~ThreadedBST() {
    delete ROOT;
    ROOT = NULL;
}

void ThreadedBST  :: create() {
    int val;
    cin >> val;

    // We take user input till we receive -1
    while (val != -1) {
        ROOT = insertIntoTree(val);
        cin >> val;
    }
}

pair<Node *, Node *> ThreadedBST  :: search(int data) {
    // Parent of current node
    Node  *parent = NULL;
    Node  *curr = ROOT;

    while (curr != NULL) {
         // Search key in BST : find Node and its parent.
        if (data == curr->data) break;

        // Update parent pointer
        parent = curr;

        if (data < curr->data) {
            // Key is smaller than current
            if (curr->lthread == false) curr = curr->left;
            else {
                curr = NULL;
                break;
            }
        } else {
            // Key is greater than current
            if (curr->rthread == false) curr = curr->right;
            else {
                curr = NULL;
                break;
            }
        }
    }

    return make_pair(parent, curr);
}

Node * ThreadedBST  :: insertIntoTree(int data) {
    pair<Node *, Node *> found = search(data);

    if (found.second && found.second->data == data) return ROOT;

    Node  *parent = found.first;

    // Create a new node
    Node  *tmp = new Node (data);

    if (parent == NULL) {
        // If there is no parent, then this is the root
        return tmp;
    } else if (data < parent->data) {
        // This becomes the left node
        // Left points to inorder pred, i.e. itself
        // Right points to succ, i.e. parent
        tmp->left = parent->left;
        tmp->right = parent;
        // Undo threading of parent
        parent->lthread = false;
        parent->left = tmp;
    } else {
        // This becomes the right node
        // Left points to pred, ie. parent
        // Right points to succ, i.e. itself
        tmp->left = parent;
        tmp->right = parent->right;
        parent->rthread = false;
        parent->right = tmp;
    }

    return ROOT;
}

Node * ThreadedBST  :: inSucc(Node * ptr) {
    // We find inorder successor using rthread
    // If rthread is set, we can quickly find it
    if (ptr->rthread == true) return ptr->right;
 
    // Else return leftmost child of right subtree
    ptr = ptr->right;
    while (ptr->lthread == false) ptr = ptr->left;
 
    return ptr;
}

Node * ThreadedBST  :: inPred(Node * ptr) {
    // We find inorder predecessor using lthread
    // If lthread is set, we can quickly find it
    if (ptr->lthread == true) return ptr->left;
 
    // Else return rightmost child of left subtree
    ptr = ptr->left;
    while (ptr->rthread == false) ptr = ptr->right;
    return ptr;
}
Node * ThreadedBST  :: deleteNoChild(Node * root, Node * par, Node * ptr) {
    // If Node to be deleted is root
    if (par == NULL) root = NULL;
    // If Node to be deleted is left of its parent
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    } else {
        par->rthread = true;
        par->right = ptr->right;
    }
 
    // Free memory and return new root
    ptr->left = ptr->right = NULL;
    delete ptr;

    return root;
}

Node * ThreadedBST  :: deleteOneChild(Node * root, Node * par, Node * ptr) {
    Node * child;
 
    // Initialize child Node to be deleted has left child.
    if (ptr->lthread == false) child = ptr->left;
    // Node to be deleted has right child.
    else child = ptr->right;
 
    // Node to be deleted is root Node.
    if (par == NULL) root = child;
    // Node is left child of its parent.
    else if (ptr == par->left) par->left = child;
    else par->right = child;
 
    // Find successor and predecessor
    Node * s = inSucc(ptr);
    Node * p = inPred(ptr);
 
    // If ptr has left subtree.
    if (ptr->lthread == false) p->right = s;
    // If ptr has right subtree.
    else if (ptr->rthread == false) s->left = p;
 
    ptr->left = ptr->right = NULL;
    delete ptr;

    return root;
}
Node * ThreadedBST  :: deleteTwoChild(Node * root, Node * par, Node * ptr) {
    // Find inorder successor and its parent.
    Node * parsucc = ptr;
    Node * succ = ptr->right;
 
    // Find leftmost child of successor
    while (succ->lthread == false) {
        parsucc = succ;
        succ = succ->left;
    }
 
    ptr->data = succ->data;
 
    // We need to check if these have children or not
    if (succ->lthread == true && succ->rthread == true) root = deleteNoChild(root, parsucc, succ);
    else root = deleteOneChild(root, parsucc, succ);
 
    return root;
}

void ThreadedBST  :: remove(int data) {
    pair<Node *, Node *> found = search(data);
    Node  *parent = found.first;
    Node  *curr = found.second;

    if (curr == NULL) return;

    if (curr->lthread == false && curr->rthread == false) {
        // Two Children
        ROOT = deleteTwoChild(ROOT, parent, curr);
    } else if (curr->lthread == false) {
        // Only Left Child
        ROOT = deleteOneChild(ROOT, parent, curr);
    } else if (curr->rthread == false) {
        // Only Right Child
        ROOT = deleteOneChild(ROOT, parent, curr);
    } else {
        // No child
        ROOT = deleteNoChild(ROOT, parent, curr);
    }
}

void ThreadedBST  :: inorder() {
    // Printing the threaded tree
    // Base NULL case
    if (ROOT == NULL) return;

    // Reach leftmost node
    Node  *ptr = ROOT;
    while (ptr->lthread == false) ptr = ptr->left;

    // One by one print successors
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = inSucc(ptr);
    }

    cout << endl;
}

void ThreadedBST  :: preorder() {
    // Base NULL case
    if (ROOT == NULL) return;

    Node  *temp = ROOT;

    while (temp != NULL) {
        // Print the value at current
        cout<<temp->data<<" ";

        while(temp->lthread == false) {		
            // While left subtree exists
            temp = temp->left;
            // Print leftmost value
            cout << temp->data << " ";		
        }

        while(temp->rthread == true && temp->right != NULL) {
            // If right is threaded then use it to go to previous node
            temp = temp->right;		
        }	

        // move to right after going leftmost
        temp = temp->right;		
    }

    cout << endl;
}

void ThreadedBST  :: leafly() {
    // Base NULL case
    if (ROOT == NULL) return;

    // Root iterator
    Node  *temp = ROOT;
    while (temp->lthread == false) temp = temp->left;

    while (temp != NULL) {
        bool leftMost = temp->left == NULL && temp->rthread == true;
        bool rightMost = temp->right == NULL && temp->lthread == true;
        bool middle = temp->lthread == true && temp->rthread == true;

        // If the node is the left most node, right most node, or
        // has both its pointers threaded, then it is a leaf node
        if (leftMost || rightMost || middle) cout << temp->data << " ";

        temp = inSucc(temp);
    }

    cout << endl;
}

int main() {
    /**
     * We generate an instance of Threaded Binary Search Tree
     */ 
    cout << "\nThis program performs operations on a Threaded Binary Search Tree\n" << endl;
    
    ThreadedBST  tbt;

    cout << "\nEnter space delimited elements of the tree, -1 indicating end of input" << endl;
    tbt.create();

    bool flag = true;
    int elem;

    while(flag) {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Insert an element into Tree" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Search for an element" << endl;
        cout << "4. Print Preorder Traversal" << endl;
        cout << "5. Print Inorder Traversal" << endl;
        cout << "6. Print Leaf Nodes" << endl;
        cout << "7. Exit" << endl;
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter the element to insert: ";
                cin >> elem;
                tbt.insertIntoTree(elem);
                cout << elem << " has been inserted." << endl;
                break;
            case 2:
                cout << "\nEnter the element to delete: ";
                cin >> elem;
                tbt.remove(elem);
                cout << "\nThe element if present, has been deleted" << endl;
                break;
            case 3:
                cout << "\nEnter the element to search for: ";
                cin >> elem;
                if (tbt.search(elem).second != NULL) {
                    cout << elem << " is present in the tree." << endl;
                } else {
                    cout << elem << " is not present in the tree." << endl;
                }
                break;
            case 4:
                cout << "\nPreorder traversal of this tree :" << endl;
                tbt.preorder();
                break;
            case 5:
                cout << "\nInorder traversal of this tree :" << endl;
                tbt.inorder();
                break;
            case 6:
                cout << "\nLeaf nodes of this tree :" << endl;
                tbt.leafly();
                break;
            case 7:
                cout << "\nGoodbye !!!" << endl;
                flag = !flag;
                break;
            default:
                cout << "\nPlease try again" << endl;
                break;
        }
    }

    cout << endl;

    return 0;
}

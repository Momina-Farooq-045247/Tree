#include <iostream>
using namespace std;

class Node
{
	public:
		Node *left;
		Node *right;
		int data;
};

class BST
{
	private:
		Node *root;
	public:
		BST()
		{
			root = NULL;
		}
		bool isEmpty()
		{
			if (root == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void print()
		{
			preOrder(root);
		}	
		void preOrder(Node *root)
		{
			if (isEmpty())
			{
				return;
			}
			else
			{
				VisitRoot(root);
				preOrder(root->left);
				preOrder(root->right);
			}
		}
		void VisitRoot(Node *root)
		{
			cout << root->data << endl;
		}
		void inOrder(Node *root)
		{
			if (isEmpty())
			{
				return;
			}
			else
			{
				inOrder(root->left);
				VisitRoot(root);
				inOrder(root->right);
			}
		}
		bool doesExist(int key)
		{
			PreOrder(root,key);
		}
		bool PreOrder(Node *root,int key)
		{
			if (!isEmpty())
			{
				if (root->data == key)
				{
					return true;
					PreOrder(root->left,key);
					PreOrder(root->right,key);
			    }
				else
				{
					return false;
				}
			}
		}
		bool isLeaf(Node *root)
		{
			if (root->left == NULL && root->right == NULL)
			{
				return true;
			}
		}
		bool isExternal(Node *root)
		{
			return isLeaf(root);
		}
		bool isInternal(Node *root)
		{
			return !isExternal(root);
		}
		bool isFullParent(Node *root)
		{
			if (root->left != NULL && root->right != NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isSingleParent(Node *root)
		{
			if(!isLeaf(root) && !isFullParent(root))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int largestElement(Node *root)
		{
			if (root->right == NULL)
			{
				return root->data;
			}
			else
			{
				largestElement(root->right);
			}
		}
		int smallestElement(Node *root)
		{
			if (root->left == NULL)
			{
				return root->data;
			}
			else
			{
				smallestElement(root->left);
			}
		}
		int successor(Node *root)
		{
			return smallestElement(root->right);
		}
		int predecessor(Node *root)
		{
			return largestElement(root->left);
		}
		Node* insert(Node* root,int x)
	    {
	        if(root == NULL)
	        {
	            root = new Node;
	            root->data = x;
	            root->left = root->right = NULL;
	        }
	        else if(x < root->data)
	        {
	            root->left = insert(root->left,x);
	    	}
	        else if(x > root->data)
	        {
	            root->right = insert(root->right,x);
	        }
	        return root;
	    }
	    void insert(int x) 
		{
        	root = insert(root,x);
    	}
    	
};

int main()
{
	BST b;
	b.insert(5);
	b.doesExist(8);
	return 0;
}

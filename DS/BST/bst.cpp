#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};
class __BST {
	struct node* start;
public:
	__BST();
	node* Insert(int, struct node*);
	node* Delete_ele(int, struct node*);
	void delete_node(struct node*);
	void Inorder();
	void Preorder();
	void Postorder();
	int FindMax(struct node*);
	int FindMin(struct node*);
	int height(struct node*);
	int noOfLeafNodes(struct node*);
	int noOfNonLeafNodes(struct node*);
	~__BST();
};
__BST::__BST(){
	start = NULL;
}
node* __BST::Insert(int element, struct node* cur) {
	if (NULL == cur) {
		struct node*temp;
		temp = new node;
		temp->data = element;
		return temp;
	}
	else {
		if (element < cur->data) {
			cur->left = Insert(element, cur->left);
		}
		else {
			cur->right = Insert(element, cur->right);
		}
		return cur;
	}
}
node* __BST::Delete_ele(int element,struct node* cur) {
	if (cur != NULL) {
		if (element > cur->data) {
			cur->right = Delete_ele(element, cur->right);
		}
		else{ 
			if (element < cur->data) {
				cur->left = Delete_ele(element, cur->left);
			}
		}
	}
	else {
		if (cur->left != NULL&&cur->right != NULL) {
			cur->data = FindMax(cur->left);
			cur->left = Delete_ele(cur->data, cur->left);
		}
		else {
			struct node* temp;
			temp = cur;
			if (NULL == cur->left) {
				cur = cur->right;
			}
			else {
				cur = cur->left;
				delete temp;
			}
		}
	}
	return cur;
}
int __BST::FindMax(struct node* cur){
	if (cur != NULL) {
		while (cur->right!=NULL)
		{	
			cur = cur->right;
		}
		return cur->data;
	}
	return -1;
}
int __BST::FindMin(struct node* cur) {
	if (cur != NULL) {
		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		return cur->data;
	}
	return -1;
}
int __BST::height(struct node* cur)
{
	if (NULL == cur) {
		return -1;
	}
	else {
		return(max(height(cur->left),height(cur->right+1)));
	}
}
int __BST::noOfLeafNodes(struct node* cur) {
	if (NULL == cur) {
		return 0;
	}
	if (NULL == cur->left&&NULL == cur->right) {
		return 1;
	}
	return (noOfLeafNodes(cur->left) + noOfLeafNodes(cur->right));
}
int __BST::noOfNonLeafNodes(struct node* cur)
{
	if (NULL == cur) {
		return 0;
	}
	if (NULL == cur->left&&NULL == cur->right) {
		return 0;
	}
	return (noOfNonLeafNodes(cur->left) + noOfNonLeafNodes(cur->right) + 1);
}
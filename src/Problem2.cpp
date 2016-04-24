/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>
int size_of_tree(struct node* root);
int size_of_tree(struct node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + size_of_tree(root->left) + size_of_tree(root->right);
}
struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int* bst_to_array(struct node* root,int* arr,int);

int* bst_to_array(struct node* root,int* arr,int index)
{
	if (root == NULL)
		return arr;
	else
	{
		bst_to_array(root->left, arr,index);
		bst_to_array(root->right, arr, index);
		arr[index] = root->data;
		index++;
	}
}

int is_identical(struct node_dll *head, struct node *root)
{
	if (head == NULL)
		return -1;
	else
	{
		int size = 0, i = 0, flag = 0, index = 0;;
		size = size_of_tree(root);
		int* arr = (int*)malloc(sizeof(int)*size);
		arr = bst_to_array(root, arr,index);
		while (i < size)
		{
			if (arr[i] == head->data)
			{
				flag = 1;
				head = head->next;
			}
			else
			{
				flag = 0;
				break;
			}
			i++;
		}
		return flag;
	}
}

//void recursive_fun(struct node_dll* head, struct node* root, int* res)
//{
//	if (head == NULL)
//		return;
//	else
//	{
//		recursive_fun(head, root->left, res);
//		recursive_fun(head, root->right, res);
//		if (root->data == head->data)
//		{
//			*res = 1;
//			head = head->next;
//		}
//		else
//		{
//			head = NULL;
//			*res = 0;
//		}
//	}
//}
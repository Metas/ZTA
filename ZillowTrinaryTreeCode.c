//C program to Implement insert and delete in a trinary tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 //Maximum Number of nodes

//Structure definition of a node in trinary tree
struct node
{
	int data;
	struct node *less;
	struct node *equal;
	struct node *greater;
}*root;

//method definitions
struct node * insert(struct node *S,int dataVal);
struct node * deleteNode(struct node *S,int dataVal);
struct node * findMax(struct node *S);
deleteTree(struct node *S);
traverseAndDisplay(struct node *S);

//Utility function to create a new node
struct node* newNode(int dataVal)
{
	struct node *nodeValue=(struct node* )malloc(sizeof(struct node));
	nodeValue->data = dataVal;
	nodeValue->less = NULL;
	nodeValue->equal=NULL;
	nodeValue->greater =NULL;
	return nodeValue;
}

//insert node
struct node * insert(struct node *S,int dataVal)
{
	struct node *temp;
	if(S ==NULL)//root node
	{
		printf("inserted node %d is the root\n",dataVal);
		temp =newNode(dataVal);
		S =temp;
		S->less =NULL;
		S->equal=NULL;
		S->greater =NULL;
		root =S;
		return S;
	}
	else
	{
		if(dataVal < S->data)//less Node
		{
			printf("dataVal %d is less than root %d\n",dataVal, S->data);
			if(S->less !=NULL)
			{
				S =insert(S->less,dataVal);
			}
			else
			{
				printf("inserted node %d to the left of root%d\n",dataVal,S->data);
				temp =newNode(dataVal);
				S->less =temp;
				return S;
			}
		}
		else if(dataVal > S->data)//greater node
		{
			printf("dataVal %d is greater than root %d\n",dataVal,S->data);
			if(S->greater !=NULL)
			{
				S =insert(S->greater,dataVal);
			}
			else
			{
				printf("inserted node %d to the right of root%d\n",dataVal,S->data);
				temp =newNode(dataVal);
				S->greater =temp;
				return S;
			}
		}
		else //it is equal
		{
			printf("dataVal %d is equal to root %d\n",dataVal,S->data);
			if(S->equal !=NULL)
			{
				S =insert(S->equal,dataVal);
			}
			else
			{
				printf("inserted node %d is equal to root %d\n",dataVal, S->data);
				temp =newNode(dataVal);
				S->equal = temp;
				return S;
			}
		}
	}
}

//Traverse the tree inORDER
traverseAndDisplay(struct node *root)
{
	if(root ==NULL)
	{
		printf("THE TREE IS EMPTY\n");
		return;
	}
	else
	{
		printf("The data is %d\n", root->data);
		
		if(root->less !=NULL)
			traverseAndDisplay(root->less);
		if(root->equal !=NULL)
			traverseAndDisplay(root->equal);
		
		if(root->greater !=NULL)
			traverseAndDisplay(root->greater);
		return;
	}
}

//delete node: replace the nodes data and delete the node that the data was replaced from
struct node * deleteNode(struct node *S,int dataVal)
{
	struct node *temp, *left;
	left =S;
	if(S== NULL)
		printf("dataVal %d not in tree\n",dataVal);
	else if(dataVal < S->data)
	{
		left =S;
		S->less = deleteNode(S->less,dataVal);
	}
	else if(dataVal >S->data)
	{
		left =S;
		S->greater = deleteNode(S->greater,dataVal);
	}
	else
	{
		//we found the element
		printf("DATA in Left%d\n",left->data);
		if(S->less && S->greater) //two children
		{
			printf("TWO CHILDREN\n");
			//replace with largest in less subtree
			temp =findMax(S->less);
			S->data = temp->data;
			S->less=deleteNode(S->less,S->data);
		}
		else if((S->less !=NULL) || (S->greater!=NULL))
		{
			//one child
			printf("ONE CHILD\n");
			temp =S;
			if(S->less ==NULL)
				S=S->greater;
			if(S->greater ==NULL)
				S=S->less;
			free(temp);
		}
		else
		{
			printf("NO CHILD\n");
			return NULL;
		}
	}
	return S;
}
deleteTree(struct node *S)
{
	if(S==NULL)
		return;
	
	deleteTree(S->less);
	deleteTree(S->equal);
	deleteTree(S->greater);
	free(S);
	root =NULL;
}
struct node * findMax(struct node * S)
{
	if(S==NULL)
		return NULL;
	else if(S->greater ==NULL)
		return S;
	else
		return findMax(S->greater);
}
main()
{
	struct node *T;
	root =NULL;
	T=root;
	insert(root,5);
	insert(root,9);
	insert(root,4);
	insert(root,5);
	insert(root,2);
	insert(root,2);
	insert(root,7);

	traverseAndDisplay(root);

	deleteNode(root,4);
	traverseAndDisplay(root);
	
	deleteNode(root,7);
	traverseAndDisplay(root);

	deleteTree(root);
	traverseAndDisplay(root);
	return 0;
}
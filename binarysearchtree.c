#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
typedef struct node *tree;
tree creatememory(int,tree,tree);
tree readele(tree);
tree insert(tree,int);
void printele(tree);
void inorder(tree);
void preorder(tree);
void postorder(tree);
int menu();
tree delete(tree,int);
tree findmin(tree);
tree findmax(tree);
int search(tree,int);
int main()
{
	tree t=NULL;
	int ele,key;
	t=readele(t);
	printele(t);
	while(1)
	{
		switch(menu())
		{
			case 0:exit(0);
			case 1:printf("Enter the Element: ");
			       scanf("%d",&ele);
			       t=insert(t,ele);
			       printele(t);
			       break;
			case 2:printf("Enter the Element: ");
			       scanf("%d",&ele);
			       t=delete(t,ele);
			       printele(t);
			       break;
			case 3:printf("Enter the Element: ");
			       scanf("%d",&ele);
			       if(search(t,ele)!=-404)
				       printf("Element Found\n");
			       else
				       printf("Element Not Found\n");
			       break;
			case 4:printf("MINIMUM: %d\n",findmin(t)->data);
			       break;
			case 5:printf("MAXIMUM: %d\n",findmax(t)->data);
			       break;
			default:printf("Invalid Choice\n");
				break;
		}
	}
}
tree creatememory(int e,tree left,tree right)
{
	tree x;
	x=(tree)malloc(sizeof(struct node));
	x->left=left;
	x->right=right;
	x->data=e;
	return x;
}
tree readele(tree t)
{
	int n,e,i;
	printf("Enter no of Elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth value: ",i+1);
		scanf("%d",&e);
		t=insert(t,e);
	}
	return t;
}
tree insert(tree t,int e)
{
	if(t==NULL)
	{
		t=creatememory(e,NULL,NULL);
	}
	else if(e<t->data)
	{
		t->left=insert(t->left,e);
	}
	else if(e>t->data)
	{
		t->right=insert(t->right,e);
	}
	return t;
}
void printele(tree t)
{
	printf("Elements in the BinarySearchTree :\n");
	printf("In-Order  : ");
	inorder(t);
	printf("\n");
	printf("Pre-Order : ");
	preorder(t);
	printf("\n");
	printf("Post-Order: ");
	postorder(t);
	printf("\n");
}
void inorder(tree t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d   ",t->data);
		inorder(t->right);
	}
}
void preorder(tree t)
{
	if(t!=NULL)
	{
		printf("%d   ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(tree t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d   ",t->data);
	}
}
int menu()
{
	int opt;
	printf("[0]:EXIT\n");
	printf("[1]:INSERT\n");
	printf("[2]:DELETE\n");
	printf("[3]:SEARCH\n");
	printf("[4]:FIND MIN\n");
	printf("[5]:FIND MAX\n");
	printf("Enter Your Choice: ");
	scanf("%d",&opt);
	return opt;
}
tree delete(tree t,int e)
{
	tree tmp;
	if(t==NULL)
		return NULL;
	else if(e<t->data)
		t->left=delete(t->left,e);
	else if(e>t->data)
		t->right=delete(t->right,e);
	else
	{
		if(t->left==NULL && t->right==NULL)
		{
			free(t);
			return NULL;
		}
		else if(t->left==NULL)
		{
			tmp=t;
			t=t->right;
			free(tmp);
		}
		else if(t->right==NULL)
		{
			tmp=t;
			t=t->left;
			free(tmp);
		}
		else
		{
			tmp=findmin(t->right);
			t->data=tmp->data;
			t->right=delete(t->right,tmp->data);
		}

	}
	return t;
}
tree findmin(tree t)
{
	tree tmp=t;
	while(tmp->left!=NULL)
		tmp=tmp->left;
	return tmp;
}
tree findmax(tree t)
{
	tree tmp=t;
	while(tmp->right!=NULL)
		tmp=tmp->right;
	return tmp;
}
int search(tree t,int e)
{
	tree tmp=t;
	while(tmp!=NULL)
	{
		if(e<tmp->data)
			tmp=tmp->left;
		else if(e>tmp->data)
			tmp=tmp->right;
		else if(tmp->data==e)
			return e;
	}
	return -404;
}


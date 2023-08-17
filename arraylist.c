#include<stdio.h>
#include<stdlib.h>
struct ArrayList
{
	int *a,n,m;
};
typedef struct ArrayList *AL;
AL creatememory(int);
void readele(AL);
void printele(AL);
int menu();
void insert(AL,int,int);
void delete(AL,int);
void deletedup(AL);
void sort(AL);
void swap(AL,int,int);
void reverse(AL);
int search(AL,int);
int minimum(AL);
int maximum(AL);
int main()
{
	AL al;
	int size,ele,pos,key;
	printf("Enter the size of ArrayList: ");
	scanf("%d",&size);
	al=creatememory(size);
	readele(al);
	printele(al);
	while(1)
	{
		switch(menu())
		{
			case 0:exit(0);
			case 1:printf("Enter an Element: ");
			       scanf("%d",&ele);
			       printf("Enter an Position: ");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=0;
			       if(pos>al->n)
				       pos=al->n;
			       insert(al,ele,pos);
			       printele(al);
			       break;
			case 2:printf("Enter an Position: ");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=0;
			       if(pos>al->n)
				       pos=al->n;
			       delete(al,pos);
			       printele(al);
			       break;
			case 3:deletedup(al);
			       printele(al);
			       break;
			case 4:sort(al);
			       printele(al);
			       break;
			case 5:reverse(al);
			       printele(al);
			       break;
			case 6:printf("Enter Searching Element: ");
			       scanf("%d",&key);
			       if(search(al,key)!=-404)
			       {
				       printf("Element found at %dth Position\n",search(al,key));
			       }
			       else
			       {
				       printf("Element Not Found\n");
			       }
			       break;
			case 7:printf("Minimum:%d\n",minimum(al));
			       break;
			case 8:printf("Maximum:%d\n",maximum(al));
			       break;
			default:printf("Invalid Choice\n");
				break;

		}
	}
}
AL creatememory(int size)
{
	AL x;
	x->a=(int*)malloc(sizeof(int)*size);
	x->n=0;
	x->m=size;
	return x;
}
void readele(AL al)
{
	int i,n;
	printf("Enter no of Elements in Array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth Element: ",i+1);
		scanf("%d",&al->a[i]);
		al->n++;
	}
}
void printele(AL al)
{
	int i;
	printf("Elements in ArrayList: ");
	for(i=0;i<al->n;i++)
	{
		printf("%d   ",al->a[i]);
	}
	printf("\n");
}
int menu()
{
	int opt;
	printf("[0]:EXIT\n");
	printf("[1]:INSERT\n");
	printf("[2]:DELETE\n");
	printf("[3]:DELETE DUPLICATES\n");
	printf("[4]:SORT\n");
	printf("[5]:REVERSE\n");
	printf("[6]:SEARCH\n");
	printf("[7]:FIND MIN\n");
	printf("[8]:FIND MAX\n");
	printf("Enter Your Choice: ");
	scanf("%d",&opt);
	return opt;
}
void insert(AL al,int ele,int pos)
{
	int i;
	for(i=al->n;i>=pos;i--)
	{
		al->a[i]=al->a[i-1];
	}
	al->a[pos-1]=ele;
	al->n++;
}
void delete(AL al,int pos)
{
	int i;
	for(i=pos-1;i<al->n;i++)
	{
		al->a[i]=al->a[i+1];
	}
	al->n--;
}
void deletedup(AL al)
{
	int i,j;
	for(i=0;i<al->n;i++)
	{
		for(j=i+1;j<al->n;j++)
		{
			if(al->a[i]==al->a[j])
			{
				delete(al,j+1);
			}
		}
	}
}
void sort(AL al)
{
	int i,j;
	for(i=0;i<al->n;i++)
	{
		for(j=i+1;j<al->n;j++)
		{
			if(al->a[i]>al->a[j])
			{
				swap(al,i,j);
			}
		}
	}
}
void swap(AL al,int i,int j)
{
	int tmp=al->a[i];
	al->a[i]=al->a[j];
	al->a[j]=tmp;
}
void reverse(AL al)
{
	int i,j;
	for(i=0,j=al->n-1;i<j;i++,j--)
	{
		swap(al,i,j);
	}
}
int search(AL al,int key)
{
	int i,flag=0;
	for(i=0;i<al->n;i++)
	{
		if(al->a[i]==key)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return i+1;
	return -404;
}
int minimum(AL al)
{
	int i,min=al->a[0];
	for(i=1;i<al->n;i++)
	{
		if(min>al->a[i])
		{
			min=al->a[i];
		}
	}
	return min;
}
int maximum(AL al)
{
	int i,max=al->a[0];
	for(i=1;i<al->n;i++)
	{
		if(max<al->a[i])
		{
			max=al->a[i];
		}
	}
	return max;
}


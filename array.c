#include<stdio.h>
#include<stdlib.h>
void readele(int[],int);
void printele(int[],int);
int menu();
void insert(int[],int,int,int);
void delete(int[],int,int);
void swap(int[],int,int);
void reverse(int[],int);
void sort(int[],int);
int search(int[],int,int);
int deletedup(int[],int);
int findmin(int[],int);
int findmax(int[],int);
int main()
{
	int arr[50],n,ele,pos;
	printf("Enter No of Elements in Array:");
	scanf("%d",&n);
	readele(arr,n);
	printele(arr,n);
	while(1)
	{
		switch(menu())
		{
			case 0:exit(0);
			case 1:printf("Enter the element:");
			       scanf("%d",&ele);
			       printf("Enter the position:");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=1;
			       if(pos>n)
				       pos=n+1;
			       insert(arr,n,ele,pos);n++;
			       printele(arr,n);
			       break;
			case 2:printf("Enter the position:");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=1;
			       if(pos>n)
				       pos=n+1;
			       delete(arr,n,pos);n--;
			       printele(arr,n);
			       break;
			case 3:reverse(arr,n);
			       printele(arr,n);
			       break;
			case 4:sort(arr,n);
			       printele(arr,n);
			       break;
			case 5:n=deletedup(arr,n);
			       printele(arr,n);
			       break;
			case 6:printf("Enter the Element:");
			       scanf("%d",&ele);
			       pos=search(arr,n,ele);
			       if(pos!=-404)
				       printf("Element found at %dth position\n",pos+1);
			       else
				       printf("Element Not Found\n");
			       break;
			case 7:printf("MINIMUM:%d\n",findmin(arr,n));
			       break;
			case 8:printf("MAXIMUM:%d\n",findmax(arr,n));
			       break;
			default:printf("Invalid Choice\n");
				break;
		}
	}
}
void readele(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter %dth Element :",i+1);
		scanf("%d",&a[i]);
	}
}
void printele(int a[],int n)
{
	int i;
	printf("Elements in Array :");
	for(i=0;i<n;i++)
	{
		printf("%d   ",a[i]);
	}
	printf("\n");
}
int menu()
{
	int opt;
	printf("[0]:Exit\n");
	printf("[1]:INSERT\n");
	printf("[2]:DELETE\n");
	printf("[3]:REVERSE\n");
	printf("[4]:SORT\n");
	printf("[5]:DELETE DUPLICATES\n");
	printf("[6]:SEARCH\n");
	printf("[7]:FIND MINIMUM\n");
	printf("[8]:FIND MAXIMUM\n");
	printf("Enter Your Choice :");
	scanf("%d",&opt);
	return opt;
}
void insert(int a[],int n,int e,int p)
{
	int i;
	for(i=n;i>=p;i--)
	{
		a[i]=a[i-1];
	}
	a[p-1]=e;
}
void delete(int a[],int n,int p)
{
	int i;
	for(i=p-1;i<n;i++)
	{
		a[i]=a[i+1];
	}
}
void swap(int a[],int i,int j)
{
	int tmp;
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}
void reverse(int a[],int n)
{
	int i,j;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		swap(a,i,j);
	}
}
void sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a,i,j);
			}
		}
	}
}
int search(int a[],int n,int e)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==e)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return i;
	return -404;
}
int deletedup(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				delete(a,n,j+1);
				n--;
			}
		}
	}
	return n;
}
int findmin(int a[],int n)
{
	int i,min=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}
int findmax(int a[],int n)
{
	int i,max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

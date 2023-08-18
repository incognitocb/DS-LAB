#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node *dlist;
dlist creatememory();
void readele(dlist);
void printele(dlist);
void append(dlist,int);
dlist endlist(dlist);
void insert(dlist,int,dlist);
dlist firstlist(dlist);
dlist nextlist(dlist);
dlist prevlist(dlist);
int menu();
dlist poslist(dlist,int);
int length(dlist);
void delete(dlist,dlist);
void deletedup(dlist);
void sort(dlist);
void swap(dlist,dlist);
void reverse(dlist);
int search(dlist,int);
int findmin(dlist);
int findmax(dlist);
int main()
{
	dlist d=creatememory();
	int ele,pos,key;
	readele(d);
	printele(d);
	while(1)
	{
		switch(menu())
		{
			case 0:exit(0);
			case 1:printf("Enter the Element: ");
			       scanf("%d",&ele);
			       printf("Enter the Position: ");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=1;
			       if(pos>length(d))
				       pos=length(d)+1;
			       insert(d,ele,poslist(d,pos-1));
			       printele(d);
			       break;
			case 2:printf("Enter the Position: ");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=1;
			       if(pos>=length(d))
				       pos=length(d);
			       delete(d,poslist(d,pos));
			       printele(d);
			       break;
			case 3:deletedup(d);
			       printele(d);
			       break;
			case 4:sort(d);
			       printele(d);
			       break;
			case 5:reverse(d);
			       printele(d);
			       break;
			case 6:printf("Enter the Element: ");
			       scanf("%d",&key);
			       if(search(d,key)!=-404)
				       printf("Element Found at %dth position\n",search(d,key));
			       else
				       printf("Element Not Found\n");
			       break;
			case 7:printf("Minimum: %d\n",findmin(d));
			       break;
			case 8:printf("Maximum: %d\n",findmax(d));
			       break;
			default:printf("Invalid Choice\n");
				break;
		}
	}
}
dlist creatememory()
{
	dlist x;
	x=(dlist)malloc(sizeof(struct node));
	x->prev=x->next=NULL;
	x->data=0;
	return x;
}
void readele(dlist d)
{
	int n,i,e;
	printf("Enter No of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth Element: ",i+1);
		scanf("%d",&e);
		append(d,e);
	}
}
void append(dlist d,int e)
{
	insert(d,e,endlist(d));
}
dlist endlist(dlist d)
{
	dlist tmp=d;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	return tmp;
}
void insert(dlist d,int e,dlist p)
{
	dlist x=creatememory();
	x->data=e;
	x->next=p->next;
	p->next=x;
	x->prev=p;
	if(x->next!=NULL)
		x->next->prev=x;
}
dlist firstlist(dlist d)
{
	return d;
}
dlist nextlist(dlist d)
{
	return d->next;
}
dlist prevlist(dlist d)
{
	return d->prev;
}
void printele(dlist d)
{
	dlist i;
	printf("Elements in D-Linked List: ");
	for(i=firstlist(d);i!=endlist(d);i=nextlist(i))
	{
		printf(" %d   ",i->next->data);
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
dlist poslist(dlist d,int p)
{
	dlist tmp=d;
	while(tmp->next!=NULL && p!=0)
	{
		tmp=tmp->next;
		p--;
	}
	return tmp;
}
int length(dlist d)
{
	dlist tmp=d;
	int cnt=0;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		cnt++;
	}
	return cnt;
}
void delete(dlist d,dlist p)
{
	p->prev->next=p->next;
	if(p->next!=NULL)
		p->next->prev=p->prev;
	free(p);
}
void deletedup(dlist d)
{
	dlist i,j;
	for(i=firstlist(d);i!=endlist(d);i=nextlist(i))
	{
		for(j=nextlist(i);j!=endlist(d);)
		{
			if(i->next->data==j->next->data)
				delete(d,j->next);
			else
				j=nextlist(j);
		}
	}
}
void sort(dlist d)
{
	dlist i,j;
	for(i=firstlist(d);i!=endlist(d);i=nextlist(i))
	{
		for(j=nextlist(i);j!=endlist(d);j=nextlist(j))
		{
			if(i->next->data>j->next->data)
			{
				swap(i,j);
			}
		}
	}
}
void swap(dlist i,dlist j)
{
	int tmp=i->next->data;
	i->next->data=j->next->data;
	j->next->data=tmp;
}
void reverse(dlist d)
{
	dlist i,j;
	int cnt=length(d);
	for(i=firstlist(d),j=prevlist(endlist(d));cnt>length(d)/2;i=nextlist(i),j=prevlist(j),cnt--)
	{
		swap(i,j);
	}
}
int search(dlist d,int e)
{
	int flag=0,cnt=0;
	dlist i;
	for(i=firstlist(d);i!=endlist(d);i=nextlist(i))
	{
		cnt++;
		if(i->next->data==e)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return cnt;
	return -404;
}
int findmin(dlist d)
{
	int min=d->next->data;
	dlist i;
	for(i=nextlist(firstlist(d));i!=endlist(d);i=nextlist(i))
	{
		if(min>i->next->data)
			min=i->next->data;
	}
	return min;
}
int findmax(dlist d)
{
	int max=d->next->data;
	dlist i;
	for(i=nextlist(firstlist(d));i!=endlist(d);i=nextlist(i))
	{
		if(max<i->next->data)
			max=i->next->data;
	}
	return max;
}


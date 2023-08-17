#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *llist;
llist creatememory();
void readele(llist);
void append(llist,int);
llist endlist(llist);
void insert(llist,int,llist);
void printele(llist);
llist firstlist(llist);
llist nextlist(llist);
int length(llist);
int menu();
llist poslist(llist,int);
void delete(llist,llist);
llist prevlist(llist,llist);
void deletedup(llist);
void sort(llist);
void swap(llist,llist);
void reverse(llist);
int search(llist,int);
int findmax(llist);
int findmin(llist);
int main()
{
	int ele,pos,key;
	llist l=creatememory();
	readele(l);
	printele(l);
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
			       if(pos>length(l))
				       pos=length(l)+1;
			       insert(l,ele,poslist(l,pos-1));
			       printele(l);
			       break;
			case 2:printf("Enter the Position: ");
			       scanf("%d",&pos);
			       if(pos<=0)
				       pos=1;
			       if(pos>length(l))
				       pos=length(l)+1;
			       delete(l,poslist(l,pos));
			       printele(l);
			       break;
			case 3:deletedup(l);
			       printele(l);
			       break;
			case 4:sort(l);
			       printele(l);
			       break;
			case 5:reverse(l);
			       printele(l);
			       break;
			case 6:printf("Enter the Element: ");
			       scanf("%d",&key);
			       if(search(l,key)!=-404)
			       {
				       printf("Element Found At %dth position\n",search(l,key));
			       }
			       else
				       printf("Elemnt Not Found\n");
			       break;
			case 7:printf("MAXIMUM: %d\n",findmax(l));
			       break;
			case 8:printf("MINIMUM: %d\n",findmin(l));
			       break;
			default:printf("Invalid Choice \n");
				break;
		}
	}
}
llist creatememory()
{
	llist x;
	x=(llist)malloc(sizeof(struct node));
	x->data=0;
	x->next=NULL;
	return x;
}
void readele(llist l)
{
	int i,n,e;
	printf("Enter Size of LinkedList: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %dth Element: ",i+1);
		scanf("%d",&e);
		append(l,e);
	}
}
void append(llist l,int e)
{
	insert(l,e,endlist(l));
}
llist endlist(llist l)
{
	llist tmp=l;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	return tmp;
}
void insert(llist l,int e,llist p)
{
	llist x;
	x=creatememory();
	x->data=e;
	x->next=p->next;
	p->next=x;
}
llist firstlist(llist l)
{
	return l;
}
llist nextlist(llist l)
{
	return l->next;
}
void printele(llist l)
{
	llist i;
	printf("Elements in LinkedList: ");
	for(i=firstlist(l);i!=endlist(l);i=nextlist(i))
	{
		printf("%d   ",i->next->data);
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
	printf("[7]:FIND MAX\n");
	printf("[8]:FIND MIN\n");
	printf("Enter Your Choice: ");
	scanf("%d",&opt);
	return opt;
}
int length(llist l)
{
	int cnt=0;
	llist tmp=l;
	while(tmp->next!=NULL)
	{
		cnt++;
		tmp=tmp->next;
	}
	return cnt;
}
llist prevlist(llist l,llist p)
{
	llist tmp=l;
	while(tmp->next!=p)
	{
		tmp=tmp->next;
	}
	return tmp;
}
llist poslist(llist l,int p)
{
	int i;
	llist pos=l;
	for(i=0;i<p;i++)
	{
		pos=pos->next;
	}
	return pos;
}
void delete(llist l,llist p)
{
	llist pos=prevlist(l,p);
	pos->next=p->next;
	free(p);
}
void deletedup(llist l)
{
	llist i,j;
	for(i=firstlist(l);i!=endlist(l);i=nextlist(i))
	{
		for(j=nextlist(i);j!=endlist(l);)
		{
			if(i->next->data==j->next->data)
				delete(l,j->next);
			else
				j=nextlist(j);
		}
	}
}
void sort(llist l)
{
	llist i,j;
	for(i=firstlist(l);i!=endlist(l);i=nextlist(i))
	{
		for(j=nextlist(i);j!=endlist(l);j=nextlist(j))
		{
			if(i->next->data>j->next->data)
				swap(i,j);
		}
	}
}
void swap(llist i,llist j)
{
	int tmp=i->next->data;
	i->next->data=j->next->data;
	j->next->data=tmp;
}
void reverse(llist l)
{
	llist i,j;
	int len=length(l);
	for(i=firstlist(l),j=prevlist(l,endlist(l));(length(l)/2)<len;i=nextlist(i),j=prevlist(l,j),len--)
	{
		swap(i,j);
	}
}
int search(llist l,int k)
{
	int cnt=0,flag=0;
	llist i;
	for(i=firstlist(l);i!=endlist(l);i=nextlist(i))
	{
		cnt++;
		if(i->next->data==k)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return cnt;
	return -404;
}
int findmin(llist l)
{
	int min=l->next->data;
	llist i;
	for(i=nextlist(firstlist(l));i!=endlist(l);i=nextlist(i))
	{
		if(min>i->next->data)
			min=i->next->data;
	}
	return min;
}
int findmax(llist l)
{
	int max=l->next->data;
	llist i;
	for(i=nextlist(firstlist(l));i!=endlist(l);i=nextlist(i))
	{
		if(max<i->next->data)
			max=i->next->data;
	}
	return max;
}

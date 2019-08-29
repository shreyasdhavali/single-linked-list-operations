#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;	
};

//////////-------- 1 print------------///////////
void print(node *n)
{
	cout<<"elements of the list are\n";
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}

//////////-------- 0 append------------///////////
void append(node* *head,int new_data)
{
	node *new_node=new node();
	node* last=*head;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
	}
	else
	{
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=new_node;
	}
	
}

//////////-------- 2 length------------///////////
int length(node* *head)
{
	int c=1;
	node* temp=*head;
	while(temp->next!=NULL)
	{
		c++;
		temp=temp->next;	
	}	
	cout<<"\nthe length of list is\n"<<c<<endl;
	return c;
}

//////////-------- 3 insert------------///////////
void insert(node* *head,int pos,int new_data)
{
	int c=1;
	node* t=*head;
	int n=length(&t);
	if(pos>n+1)
	{
		cout<<"length of the list is excided\n";
		return;
	}
	node *new_node=new node();
	new_node->data=new_data;
	new_node->next=NULL;
	node *temp=*head;
	if(pos==1)
	{
		new_node->next=*head;
		*head=new_node;	
		node* t=*head;
		print(t);
		return;		
	}
	while(temp!=NULL)
	{
		c+=1;
		if(pos==c)
		{
			new_node->next=temp->next;
			temp->next=new_node;
			node* t=*head;
			print(t);
			return;				 	
		}	
		else
		{
			temp=temp->next;
		}
		
	}
}

//////////-------- 4 delete value------------///////////
void delete_value(node* *head,int value)
{
	int b=0;
	node* temp=*head;
	if(temp->data==value)
	{
		node* t=*head;
		t=t->next;
		print(t);
		b=1;
	}
	while(temp->next!=NULL)
	{
		if(temp->next->data==value)
		{
			temp->next=temp->next->next;
			node* t=*head;
			print(t);
			b=1;
		}
		else
		{
			temp=temp->next;
		}
    }
    if(b==0)
    	cout<<"\n"<<value<<" doesnt exits\n";
	
}


//////////--------main function------------///////////
int main()
{
	int i,n,x,t,pos,value;
	node *head=NULL;
	cout<<"Enter the number of elements to the list\n";
	cin>>n;
	cout<<"Enter the elements of the list\n";
	for(i=0;i<n;i++)
	{
		cin>>x;
		append(&head,x);
	}
	loop:
	cout<<"\nlinked list operations enter\n"<<endl;
	cout<<"1  for printing the list\n";
	cout<<"2  for printing the length of the list\n";
	cout<<"3  for inserting a value at specified position  in the list\n";
	cout<<"4  for deleting a value from  the list\n";
	cout<<"5  to exit\n";
	cout<<"\nEnter your choice: \n";
	cin>>t;
	switch(t)
	{
		case 1:print(head);
			   break;
		case 2:length(&head);
			   break;
		case 3:cout<<"enter the position and value to be inserted 1 being the 1st position\n";
			   cin>>pos>>value;
			   insert(&head,pos,value);
			   break;
		case 4:cout<<"enter the value u want to delete\n";
			   int a;
			   cin>>a;
			   delete_value(&head,a);
			   break;
		case 5:exit(0);
	}
	goto loop;
	return 0;
}

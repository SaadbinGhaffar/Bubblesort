#include<iostream>
using namespace std;
class Node{
	private:
		int val;
		Node *next;
		Node *prev;
		

	public:
		void setval(int v)
		{
			val=v;
		}
		int getval()
		{	
		return val;
	}
	void setnext(Node *n)
	{
		next=n;
	}
	Node *getnext()
	{	
	return next;
}   
    void setprev(Node *p)
    {
    	prev=p;
	}
	Node *getprev()
	{
		return prev;
	}
};

class Bubble{
	private:
	Node *current;
	Node *head;
	Node *next;
	Node *prev;
	Node *last;
	int size;
	public:
		Bubble()
		{
			head=NULL;
			current=NULL;
			prev=NULL;
			size=0;
		}
		void AddNode(int v)
		{
			Node *temp=new Node();
			temp->setval(v);
			if(head==NULL)
			{
				temp->setnext(NULL);
				temp->setprev(NULL);
				current=temp;
				head=temp;
				size++;
			}
			else
			{
				current->setnext(temp);
				temp->setprev(current);
				temp->setnext(NULL);
				current=temp;
				size++;
			}
		}
		void Display()
		{
			Node *temp=head;
			do{
				cout<<temp->getval()<<" ";
				temp=temp->getnext();
			}while(temp!=NULL);
		}
		void BUBBLESORT()
		{
			bool flag=true;
			Node *neo=new Node();
			Node *temp;
			Node *temp2;
			do{
			
			for(temp=head;temp->getnext()!=NULL;temp=temp->getnext())
			{
				for(temp2=temp->getnext();temp2!=NULL;temp2=temp2->getnext())
				
				if(temp->getval()>temp2->getval())
				{
					neo->setval(temp->getval());
					temp->setval(temp2->getval());
					temp2->setval(neo->getval());
					flag==true;
				}
			}
		}while(flag==false);
		}
		
		
		/////////////////////////////////
		void SelectionSort()
		{
			Node *tempmin;
			Node *tempi;
			Node *tempj;
			Node *temps=new Node();
			for(tempi=head;tempi->getnext()!=NULL;tempi=tempi->getnext())
			{
				 tempmin=tempi;
				for(tempj=tempi->getnext();tempj!=NULL;tempj=tempj->getnext())
				{
					if(tempj->getval()<tempi->getval())
						tempmin=tempj;
				}
				temps->setval(tempi->getval());
				tempi->setval(tempmin->getval());
				tempmin->setval(temps->getval());
				
			}
		}
	};
	int main()
	{
		
	Bubble b;
	int x,n,choice;
	cout<<"How Many elements you want to enter"<<endl;
	cin>>n;
    cout<<"Enter  Elements\n";
    for(int i=0;i<n;i++)
	{
		cin>>x;
		b.AddNode(x);
	}
	cout<<"BUBBLE SORT\n";
	cout<<"SELECTION SORT\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
	{
		cout<<"After BUBBLE SORT\n";
	b.BUBBLESORT();
	b.Display();
	break;
}
		case 2:
	{
		cout<<"After SELECTION SORT\n";
			b.SelectionSort();
		b.Display();
		break;		
	}
	
	}
}

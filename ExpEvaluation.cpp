#include<iostream>
#include<string>
using namespace std;
class cnode{
	public:
		cnode *next;
		char value;
};
class cstack{
	cnode *head;
	cnode *tail;
	public:
		cstack(){
			head=NULL;
			tail=NULL;
		}
		void push(char data){
			cnode *ptr=new cnode;
			ptr->value=data;
			ptr->next=NULL;
			if(head==NULL){
				head=ptr;
				tail=ptr;
			}
			else{
				tail->next=ptr;
				tail=ptr;
			}
		}


		int pop(){
			cnode *prev,*forward;
			prev=head;
			if(head==NULL){
				return 'l';
			}
			else if(prev->next==NULL){
				char temp;
				temp=head->value;
				head=NULL;
				return temp;
			}
			else{
				forward=head->next;
			
				if(head!=NULL){
				while(forward->next!=NULL){
					prev=prev->next;
					forward=forward->next;
				}
				tail=prev;
				char storage;
				storage=forward->value;
				prev->next=NULL;
				delete(forward);
				return storage;
			}
			}

		}
		void display(){
			cnode *ptr;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->value<<endl;
				ptr=ptr->next;
			}
		}
};

string postfix(string input){
	string result="";
	cstack s;
	int counter=0;
	for(int i=0;i<input.length();i++){
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
			char value;
			value=s.pop();
			if(value=='l'){
				s.push(input[i]);
			
			}
			else if(input[i]=='+'||input[i]=='-'){
				while(value=='*'||value=='/'){
					result=result+value;
					value=s.pop();
				}
				if(value!='l'){
					s.push(value);
				}
				s.push(input[i]);
			}
			else if(input[i]=='*'||input[i]=='/'){
				s.push(value);
				s.push(input[i]);
			
			}
		}
		else if(input[i]=='('||input[i]==')'){
				if(input[i]=='('){
					s.push(input[i]);
				}
				else if(input[i]==')'){
					char popstart=s.pop();
					while(popstart!='('){
						result+=popstart;
						popstart=s.pop();			
					}
				}
			}
		else{
			result+=input[i];
		}
	}
	char last=s.pop();
	 while(last!='l'){
		 result+=last;
	 	last=s.pop();
	 }
	 return result;
}
class node{
	public:
	int data;
	node* next;
};
class linkedList{
	public:
	node* head;
	node* tail;
	linkedList()
	{
		head=NULL;
		tail=NULL;
	}
};
class stack{
	private:
		linkedList l;
	public:
		void push(int a)
		{
			node* ptr=new node;
			ptr->data=a;
			if(l.head==NULL)
			{
				l.head=ptr;
				l.tail=ptr;
			}
			else
			{
				node* tptr;
				tptr=l.head;
				l.head=ptr;
				l.head->next=tptr;
			}
		}
		int pop()
		{
			if (l.head==NULL)
			{
				return -1;	
			}
			else if(l.head==l.tail)
			{
				node *tptr;
				tptr=l.head;
				l.head=NULL;
				l.tail=NULL;
				return tptr->data;
			}
			else
			{
				node *tptr;
				tptr=l.head;
				l.head=tptr->next;
				return tptr->data;
			}
			
		}
		void display()
		{
			cout<<"DISPLAY"<<endl;
			if(l.head==NULL)
			{
				cout<<"Stack is Empty"<<endl;
			}
			else
			{
				node *tptr;	
				tptr=l.head;
				while(tptr!=l.tail)
				{
					cout<<tptr->data<<endl;
					tptr=tptr->next;
				}
				cout<<l.tail->data<<endl;
			}
		}
	void Evaluatepostfix(string str)
	{
		int t1, t2, t3;
		for (int i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i]))
			{
				push(str[i] - '0');
			}
			if (str[i] == '+')
			{
				t2 = pop();
				t1 = pop();
				t3 = t1 + t2;
				this->push(t3);
			}
			if (str[i] == '*')
			{
				t2 = pop();
				t1 = pop();
				t3 = t2 * t1;
				this->push(t3);
			}
			if (str[i] == '-')
			{
				t2 = pop();
				t1 = pop();
				t3 = t1 - t2;
				this->push(t3);
			}
			if (str[i] == '/')
			{
				t2 = pop();
				t1 = pop();
				t3 = t1 / t2;
				this->push(t3);
			}
		}
		t3 = pop();
		cout << t3 << endl;
	}

	
};
int main()
{	
	string input,a;
	cout<<"enter your infix expression :";
	cin>>input;
	a=postfix(input);
	stack s;
	cout<<"PostFix:"<<a<<endl<<"Result: ";
	s.Evaluatepostfix(a);
	return 0;
}

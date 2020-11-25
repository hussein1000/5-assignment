/*
 * Name: Hussein saleh hussein
 * Class: Second class
 * Department: Neelain University - Computer Engineering*/
 
/*iostream stands for standard input-output stream this header file
 *  contains definitions to objects like cin, cout, cerr etc ...*/
#include <iostream>
/*it is short for charachter which is a data type that holds one
 *charachter, and the number is its maximum allowed length*/
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}
struct node {
	int info;
	struct node *next;
	}*start;
	// class declration
	class list {
		/*puplic is for be available at any function*/
		public:
			node* create_node(int);
			void insert_begin();
			void insert_pos();
			void insert_last(); 
			void delete_pos();
			void search();
			void displayx();
			list() {
				start = NULL;
			}
	};//class end
/*creat list with only integer*/
node *list::create_node(int value)
		{
		struct node *temp;
		temp = new(struct node);
		/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
		if (temp == NULL){
			cout<<"\nMemory allocation issue"<<endl;
			exit(1);
		}
		else {
			temp->info = value;
			temp->next = NULL;     
			return temp;
		}
		}
/*function to insert elements in begining*/
void list::insert_begin()
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *p;
			temp = create_node(value);
			/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			if (start == NULL) {
				start = temp;
				start->next = NULL;
			}
			else
			{
				p = start;
				start = temp;
				start->next = p;
			}
			cout<<"\nElement Inserted at beginning"<<endl;
		}
/*function to insert elements in last*/
void list::insert_last()
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *s;
			temp = create_node(value);
			s = start;
			while (s->next != NULL)
			{
				s = s->next;
			}
			temp->next = NULL;
			s->next = temp;
			cout << "\nElement Inserted at last" << endl;  
		}
/*function to insert elements in position*/
void list::insert_pos()
		{
			int value, pos, counter = 0; 
			cout << "\nEnter the value to be inserted: ";
			cin >> value;
			struct node *temp, *s, *ptr;
			temp = create_node(value);
			cout << "\nEnter the postion at which node to be inserted: ";
			cin >> pos;
			int i;
			s = start;
			while (s != NULL)
			{
				s = s->next;
				counter++;
			}
			/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			if (pos == 1) {
				if (start == NULL) {
					start = temp;
					start->next = NULL;
				}
				else {
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}
			else if (pos > 1  && pos <= counter) {
				s = start;
				for (i = 1; i < pos; i++) {
					ptr = s;
					s = s->next;
				}
				ptr->next = temp;
				temp->next = s;
			}
			else {
				cout<<"\nPositon out of range"<<endl;
			}
		}
	/*function to delete elements*/
void list::delete_pos() {
			int pos, i, counter = 0;
			if (start == NULL) {
				cout<<"\nList is empty"<<endl;
				return;
			}
			cout<<"\nEnter the position of value to be deleted: ";
			cin>>pos;
			struct node *s, *ptr;
			s = start;
			/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
			if (pos == 1) {
				start = s->next;
			}
			else {
				while (s != NULL) {
					s = s->next;
					counter++;  
				}
				if (pos > 0 && pos <= counter) {
					s = start;
					for (i = 1;i < pos;i++) {
						ptr = s;
						s = s->next;
					}
					ptr->next = s->next;
				}
				else {
					cout<<"\nPosition out of range"<<endl;
				}
				free(s);
				cout<<"\nElement Deleted"<<endl;
			}
		}
	/*function to search element*/
void list::search() {
	int value, pos = 0;
	bool flag = false;
	/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
	if (start == NULL) {
		cout<<"\nList is empty"<<endl;
		return;
	}
	cout<<"\nEnter the value to be searched: ";
	cin>>value;
	struct node *s;
	s = start;
	while (s != NULL) {
		pos++;
		if (s->info == value) {
			flag = true;
			cout<<"\nElement "<<value<<" is found at position "<<pos<<endl;
		}
		s = s->next;
	}
	if (!flag)
	cout<<"\nElement "<<value<<" not found in the list"<<endl;
}
/*function to display element*/
void list::displayx() {
	struct node *temp;
	if (start == NULL) {
		cout<<"\nThe List is Empty"<<endl;
		return;
	}
	temp = start;
		cout << "\nElements of the list are: " << endl;
		while (temp != NULL) {
			cout << temp->info << " --> ";
			temp = temp->next;
		}
	cout<<"null"<<endl;
}
/*function to dalete from stack*/
void pop() {
	if (top == NULL){
		cout << "\nStack Underflow!" << endl;
	}
	else {
		cout << "\nThe popped element is: " << top->data << endl;
		top = top->next;
	}
}
/*function to display stack*/
void display() {
	struct Node* ptr;
	if(top == NULL)
	cout << "\nStack is empty";
	else {
		ptr = top;
		cout << "Stack elements are: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
/*define queue elements*/
int queue[500], n = 500, front = - 1, rear = - 1;
/*function to insert element*/
void Insert() {
	int val;
	if (rear == n - 1)
	cout << "\nQueue Overflow" << endl;
	else {
		if (front == - 1)
		front = 0;
		cout << "\nThe element you want to insert in Queue: ";
		cin >> val;
		rear++;
		queue[rear] = val;
	}
}
/*function to delete element*/
void Delete() {
	if (front == - 1 || front > rear) {
		cout << "\nQueue Underflow!" << endl;
		return ;
	} else {
		cout << "\nElement deleted from queue is: " << queue[front] << endl;
		front++;;
	}
}
/*function to display elements*/
void Display() {
	if (front == - 1)
	cout << "\nQueue is empty" << endl;
	else {
	cout << "\nQueue elements are: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i]<<" ";
		cout << endl;
}
}
/*data type that hold integer*/
int A;
/*it means that our functions needs to return some integer at the end
 *of the execution and we do so by returning zero at the end of
 *the program and it means the success of the program*/
int main(){
	cout << "1 for Linked List, 2 for Stack, 3 for Queue, 4 for exit";
	cout << "\n\nWhat data structure type do you want: ";
	cin>>A;
	/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
	if (A == 3){
		int ch;
		cout << "\n1- Insert element to Queue" << endl;
		cout << "2- Delete element from Queue" << endl;
		cout << "3- Display all the elements of Queue" << endl;
		cout << "4- Exit" << endl;
		do {
		/*run code continuosly until it is breaked*/
			cout << "\nEnter your choice : ";
			cin >> ch;
			if (isdigit(ch) == 1) {
				throw "You can only use integer";
			}
			switch (ch) {
			/*switch for options when press keys*/
				case 1: Insert();
					break;
				case 2: Delete();
					break;
				case 3: Display();
					break;
				case 4:
					exit(1);// termninating case to escpae from while and terminate
				default:
					cout<<"\nInvalid choice"<<endl;
					break;
			}
	} while(ch!=4); // loop for infinite running expect when 4 is pressed which is terminating case
	}
	else if (A == 2){
		int ch, val;
		cout << "\n1- Push in Stack" << endl;
		cout << "2- Pop from Stack" << endl;
		cout << "3- Display Stack" << endl;
		cout << "4- Exit" << endl;
		do {
		/*run code continuosly until it is breaked*/
			cout << "\n\nEnter your choice: ";
			cin >> ch;
			if (isdigit(ch) == 1) {
				throw "You can only use integer";
			}
			else if (isdigit(val) == 1) {
				throw "You can only use integer";
			}
			switch(ch) {
			/*switch for options when press keys*/
				case 1: {
					cout << "\nEnter a value to be pushed: ";
					cin >> val;
					push(val);
					break;
				}
				case 2: {
					pop();
					break;
				}
				case 3: {
					display();
					break;
				}
				case 4: {
					exit(1);// termninating case to escpae from while and terminate
				}
				default: {
					cout << "\nInvalid Choice" << endl;
					break;
				}
			}
		} while(ch!=4); // loop for infinite running expect when 4 is pressed which is terminating case
	}
	else if (A == 1) {
		int choice;
		list sl;
		/*make variable for holing list value*/
			start = NULL;
			if (isdigit(choice) == 1) {
				throw "You can only use integer";
			}
			/*loop forever until condition is met*/
			while (1)
			{
				cout<<"\n1- Insert element at beginning"<<endl;
				cout<<"2- Insert element at last"<<endl;
				cout<<"3- Insert element at position"<<endl;
				cout<<"4- Delete element"<<endl;
				cout<<"5- Search element"<<endl;
				cout<<"6- Display element"<<endl;
				cout<<"7- Exit "<<endl;
				cout<<"\nEnter your choice: ";
				cin >> choice;
				switch(choice){
				/*switch for options when press keys*/
				case 1:
					sl.insert_begin();
					cout<<endl;
					break;
				case 2:
					sl.insert_last();
					cout<<endl;
					break;
				case 3:
					sl.insert_pos();
					cout<<endl;
					break;
				case 4:
					sl.delete_pos();
					break;
				case 5:
					sl.search();
					cout<<endl;
					break;
				case 6:
					sl.displayx();
					cout<<endl;
					break;
				case 7:
					exit(1);// termninate case to escpae from while
				default:
					cout<<"\nWrong choice"<<endl;
					break;
				}
			}
	}
	else if (A == 4) {
		return 0;//exit when enter 4
	}
	/*using else to specify a block of code to be executed when if
 *condition is false*/
	else {
		cout << "\nWrong choice\n" << endl;
		exit(1);
	}
	/*returning value to the main and 0 is success to state that the
 *program is working fine*/
	return 0;
}

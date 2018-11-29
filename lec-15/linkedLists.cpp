#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

struct LinkedList{
	Node* head;
	Node* tail;
};


LinkedList* createSmallLinkedList(int x, int y){
	LinkedList* newList = new LinkedList;
	newList->head = NULL;
	newList->tail = NULL;
	Node* head = NULL; //empty linked list
	head = new Node; //first node
	head->data = x;
	head->next = new Node;
	head->next->data = y;
	head->next->next = NULL;
	newList->head = head;
	newList->tail = head->next;

	return newList;

}

void insertNode(LinkedList* list, int x){
	// Adds a new node with data x at the head of the list
	// returns the new head of the list
	Node* p = new Node;
	p->data = x;
	p->next = list->head;
	if(list->head == NULL){
		list->tail = p;
	}
	list->head = p;

}
void insertLast(LinkedList* list, int x){
	 Node* p = new Node;
	 p->data = x;
	 p->next = NULL;
	 if(list->head){
	   list->tail->next = p;
	 }else{
	   list->head = p;
	 }
	 list->tail =p;
}

void freeHelper(Node* head){
	if(!head)
		return;
	freeHelper(head->next);
	delete head;

}
void freeListRecursive(LinkedList* list){
	freeHelper(list->head);
	delete list;
}

void freeList(LinkedList* list){
      // free all the nodes in the linked list
      Node* p = list->head;
      while(p){
		Node* tmp = p;
		p = p->next;
		delete tmp;
      }
      /* Do this step and stop if you are only clearing the list*/
      list->head = NULL;
      list->tail = NULL;

      /* Otherwise */
      delete list;

}

void printLinkedList(LinkedList* list){
	Node* p = list->head; //p is a traversal pointer
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}

}
/* Precondition: Linked list has atleast one node

*/
int minOfList(Node* head){
	if(head->next == NULL) {// One node linked list
		return head->data;   //Base case
	}
	int minOfRestOfList = minOfList(head->next);
	if (minOfRestOfList< head->data)
		return minOfRestOfList;
	else
		return head->data;


}

bool search(Node* head, int value){
	return true;

}


int main(){
	LinkedList* newlist= createSmallLinkedList(10, 20);
	cout<<"Initial two node list with values 10, 20:"<<endl;
	printLinkedList(newlist); // 10 20
	for(int i =0; i <10; i++){
		insertNode(newlist, i*100);
	}
	cout<<"Linked List after adding 30 to the head"<<endl;
	printLinkedList(newlist); // 30 10 20 
	cout<<"Min element is "<<minOfList(newlist->head)<<endl;
	string result;
	result = search(newlist->head, 100)?"Yes":"No";
	cout<<"Is 100 in the list?  "<< result<<endl;
	result = search(newlist->head, -100)?"Yes":"No";
	cout<<"Is -100 in the list?  "<< result<<endl;
	freeListRecursive(newlist);
	return 0;

}

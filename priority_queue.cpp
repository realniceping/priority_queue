#include <iostream>

using namespace std;

struct node {
	int value;
	int priority;
	node* next_node;
};

int* queue_init(int v, int p) {
	
	node* nodeptr = new node;
	nodeptr->value = v;
	nodeptr->priority = p;
	nodeptr->next_node = nullptr;
		
	return (int*)nodeptr;
	
	/*nfirst.value = v;
	nfirst.priority = p;
	nfirst.next_node = NULL;
	nptr = &nfirst;
	int* vptr;
	vptr = (int*)(&nfirst.value);
	cout << vptr << endl;
	return vptr;*/

}

int* queue_take_last(int* first) {
	
	node* nodeptr = (node*)first;
	node* taken_node = new node;
	int* returnP = first;
	taken_node->value = nodeptr->value;
	taken_node->priority = nodeptr->priority;
	taken_node->next_node = nodeptr->next_node;

	while (taken_node->next_node != nullptr) {
		returnP = (int*)taken_node->next_node;
		taken_node->value = taken_node->next_node->value;
		taken_node->priority = taken_node->next_node->priority;
		taken_node->next_node = taken_node->next_node->next_node;
		
	}

	delete taken_node;

	return returnP;
}

void queue_append(int* first, int v, int p) {
	
	int* lastptr = queue_take_last(first);
	node* append_nodePtr = new node;
	append_nodePtr->value = v;
	append_nodePtr->priority = p;
	append_nodePtr->next_node = nullptr;
	((node*)lastptr)->next_node = append_nodePtr;

}

int queue_get_higest_priority(int* first) {

	//anyway we should run for all list to take higest priority
	//take the first node priority and run while last_node != nullprt 
	//if next_node priority > taken priority, we should update value in higest priority
	int higest_priority = ((node*)first)->priority;
	node* tempPtr = new node;
	tempPtr->value = ((node*)first)->value;
	tempPtr->priority = ((node*)first)->priority;
	tempPtr->next_node = ((node*)first)->next_node;

	while(tempPtr->next_node != nullptr) {
		if (tempPtr->next_node->priority > higest_priority) {
			higest_priority = tempPtr->next_node->priority;
		}
		tempPtr->value = tempPtr->next_node->value;
		tempPtr->priority = tempPtr->next_node->priority;
		tempPtr->next_node = tempPtr->next_node->next_node;
	} 

	delete tempPtr;

	return higest_priority;

}

int* queue_pop(int* firstptr) {

	//1)first thing first
	//we should take first higest priority node that we found first
	//for this case i will write function that will return int higets_priority
	int higest_priority = queue_get_higest_priority(firstptr);
	//2) after that we should again run for each element in list 
	//if taken node priority == higest_priotiry get return and reconnect lits to next node
	
	node* prevPtr = new node; // take the first node copy 

	prevPtr->value = ((node*)firstptr)->value;
	prevPtr->priority = ((node*)firstptr)->priority;
	prevPtr->next_node = ((node*)firstptr)->next_node;

	if (prevPtr->next_node == nullptr) {
		return firstptr;
	}

	if (prevPtr->next_node->next_node == nullptr) {
		node* toReturn = ((node*)firstptr)->next_node;
		((node*)firstptr)->next_node = nullptr;
		return (int*)toReturn;
	}
		
	node* nextPtr = new node; // take the second node copy
	nextPtr->value = ((node*)firstptr)->next_node->value;
	nextPtr->priority = ((node*)firstptr)->next_node->priority;
	nextPtr->next_node = ((node*)firstptr)->next_node->next_node; // here we have 3 case 1)we have 3+ elemenet in queue and we can go to while
																					//   2)we have only 2 element 
	
	
	while (nextPtr->next_node->priority != higest_priority) {						
		prevPtr->value = nextPtr->value;
		prevPtr->priority = nextPtr->priority;
		prevPtr->next_node = nextPtr->next_node;
		nextPtr->value = nextPtr->next_node->value;
		nextPtr->priority = nextPtr->next_node->priority;
		nextPtr->next_node = nextPtr->next_node->next_node;
	}

	node* retur_node = nextPtr->next_node;
	node* pre_return = prevPtr->next_node;
	node* after_return = nextPtr->next_node->next_node;
	delete prevPtr, nextPtr;
	pre_return->next_node = after_return;

	return (int*)retur_node;


}



int main()
{
	
	int* queueFirst= queue_init(10, 1);
	queue_append(queueFirst, 9, 2);
	queue_append(queueFirst, 8, 3);
	queue_append(queueFirst, 7, 4);
	queue_append(queueFirst, 6, 5);

	int* queue_higest = queue_pop(queueFirst);
	cout << ((node*)queue_higest)->value << endl;
	cout << ((node*)queue_pop(queueFirst))->value << endl;
	cout << ((node*)queue_pop(queueFirst))->value << endl;
	cout << ((node*)queue_pop(queueFirst))->value << endl;
	cout << ((node*)queue_pop(queueFirst))->value << endl;
	cout << ((node*)queue_pop(queueFirst))->value << endl;
	
}

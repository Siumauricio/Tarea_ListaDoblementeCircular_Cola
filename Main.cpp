#include "Queue.h"
#include <iostream>
using namespace std;

int main(){
	Queue<int>*lista=new Queue<int>;
	lista->Enqueue (1);
	lista->Enqueue (2);
	lista->Enqueue (3);
	lista->Enqueue (4);
	lista->Dequeue ();
	cout << lista->Peek ();
	return 0;
}
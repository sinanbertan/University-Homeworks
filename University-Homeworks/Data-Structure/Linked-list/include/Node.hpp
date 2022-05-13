#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

//listeye atılacak node yazımı
struct Node{
	 string data;
	 Node *next;
	 Node *prev;
		
	 Node(const string data,Node *next=NULL,Node *prev=NULL){
		this->data = data;
		this->next = next;
		this->prev = prev;
	 }
};
#endif
/*******************************************************************************
  Title          : sortedlist.h
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Interface to the Sortedlist template class
  Purpose        : To provide methods for hotspotlist class, so it can use the templates.
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__

#include <iostream>
#include "hotspot.h"
#include <string>


using namespace std;
//create a singly-linked list
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class Sortedlist
{
public:
	Sortedlist();//constructor
	int write(ostream &os);//print function
	int insert(const T &element);//insert function
	int remove(T &element);//delete function
	int retrieve(int element,T &element1);//retrieve function
	int make_empty();//make empty function
	int get_size();//to get the size
	bool insert_at(Node<T>*  &prev, T element);//to insert at position
	int find_distance(double latitude,double longitude,double distance,ostream &os);


private:
	Node<T> *head;
	int size;
	int count;


};






//include the implementation of the template class, because it is not a real class.
#include "sortedlist.cpp"
#endif /*__SORTEDLIST_H__*/
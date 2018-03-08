/*******************************************************************************
  Title          : sortedlist.cpp
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Implementation to the sortedlist template class
  Purpose        : To provide methods of how to sort saved data
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#include <iostream>
#include <string>
#include "sortedlist.h"
#include "hotspot.h"



using namespace std;

template<class T>
Sortedlist<T>::Sortedlist()
{
	//constructor set head points to nothing
	head=NULL;
	//size to 0
	size=0;
	count=0;
}
template<class T>
int Sortedlist<T>:: write(ostream &os)
{
	Node<T>* current;
	int num_wirte;
	//empty list
	if(NULL==head)
	{
		return 0;
	}
	//list is not empty
	current=head;
	while(current!=NULL)
	{
		current->data.print(os);
		current=current->next;
		num_wirte++;

	}
	return num_wirte;
}
template<class T>
bool Sortedlist<T>:: insert_at(Node<T>*  &prev, T element)
{
	//create a node points to new node without data
	Node<T>* node=new Node<T>;
	//it cant be empty so if the condition is meet, it is false
	if(NULL==node)
	{
		return false;
	}
	//let the node points to item we want to insert
	node->data=element;
	//node next points to our original pointer points
	node->next=prev;
	//now prev points where the new node used to point to. since we insert on front 
	prev=node;
	return true;
}


template<class T>
int Sortedlist<T>:: insert(const T &element)
{
	//set a current pointer,and previous pointer.
	Node<T>* current;
	Node<T>* previous;
	bool success;
	//if the head is empty or the element to insert is smaller than the head data
	//which means we have to insert it on front to form a sortedlist
	if(NULL==head||element< head->data)
	{
		//bool success equal to call the function insert_at, and pass the parameter the pointer and the item to insert
		success= insert_at(head,element);
		//if success which means it is inserted
		if(success)
		{
			//increase the size and return the int value, in this case return 1 if successful and 0 if not.
			size++;
			return 1;
		}
		else
			return 0;

	}
	//if the data is euqal to the item we want to insert, which means it is already there.
	else if(head->data==element)
	{
		//call it unsuccessful, and quit because it is on the list.
		return 0;
	}
	//in this case, head->data is smaller than element
	else//(head->data<element)
	{
		//let previous equal to the head(start)
		previous= head;
		//current equal to the one after head
		current= head->next;
		//use while loop, it stops when current is empty
		while(current!=NULL)
		{
			//if the current is still smaller than the item
			if(current->data<element)
			{
				//increase current to the next one, and previous become current
				previous=current;
				current=current->next;
			}
			//while the item is smaller than the current one
			//and we want to insert it in linked list method
			else if(element<current->data)
			{
				success= insert_at(previous->next,element);
				if(success)
				{
					size++;
					return 1;
				}
			}
			else
				return 0;
		}//out of while loop.
		//when reach the tail, means that the item is bigger than everything in the list
		//and previous points to last node(current is null)
		success= insert_at(previous->next,element);
		if(success)
		{
			size++;
			return 1;
		}
		else
			return 0;
		return 0;
	}
}
template<class T>
int Sortedlist<T>:: remove(T &element)
{
	Node<T>* current;
	Node<T>* previous;
	//if the list is not empty, if empty we can't do anything
	if(NULL!=head)
	{
		//let current points to where head points to
		current= head;
		//previous points null at this point
		previous= NULL;
		//since head is not empty so current is not empty at this point
		while(current!=NULL)
		{
			//if the element is greater than the data current points to
			if(current->data<element)
			{
				//we move to current points to next data
				previous=current;
				current=current->next;
			}
			else if(element<current->data)
			{
				//element is smaller than current elment
				//the element might no be on the list
				return 0;
			}
			else//current->data==element
			{
				//if previous is empty which means above conditions are not meet
				//so the first node equal to the element
				if(NULL==previous)
				{
					//let head points to the next node
					head=current->next;
					//set the one current is point to, next to null which means it links to nothing
					current->next =NULL;
					//delete this node
					delete current;
					//and let current points to where head points again
					current=head;
					//decrease the size since we just delete one node
					--size;

					return 1;
				}
				else//in this case, not first node
				{
					//at this point current points to the node we want to delete, so we move current points to the next one
					current=current->next;
					//and let the one which current orginally point to link to nothing
					previous->next->next=NULL;
					//delete this node
					delete previous->next;
					//and link to the one which current points to which is the one originally after the node we deleted
					previous->next=current;
					//sicne we delted one, we decrease the size.
					--size;
					return 1;
				}
			}
		}
		return 0;
	}
	else 
		return 0;
}
template<class T>
int Sortedlist<T>:: retrieve(int element, T& element1)
{
	Node<T>* current;
	int temp_ObjectID;
	string temp_Boro;
	string temp_Type;
	string temp_Provider;
	string temp_Name;
	string temp_Location;
	double temp_Latitude;
	double temp_Longitude;
	string temp_SSID;
	//empty list
	if(NULL==head)
	{
		return 0;
	}
	current=head;
	//current points to where head points to
	while(current!=NULL)
	{
		//use get method, to find the member variable of this data
		current->data.get(temp_ObjectID,temp_Boro,temp_Type,temp_Provider,temp_Name,temp_Location,temp_Latitude,temp_Longitude,temp_SSID);
		//if the objectid is smaller than the Id we want to find
		//move pointer to next node
		if(temp_ObjectID<element)
		{
			current=current->next;
		}
		else if(temp_ObjectID>element)
		{
			//item is not on the list
			return 0;
		}
		else//means temp_objectid equal to element, the item is found.
		{
			//copy the data to element1.
			element1=current->data;
			return 1;
		}
	}
	return 0;
}

template<class T>
int Sortedlist<T>:: find_distance(double latitude,double longitude,double distance,ostream &os)
{
	Node<T>* current;
	int temp_ObjectID;
	string temp_Boro;
	string temp_Type;
	string temp_Provider;
	string temp_Name;
	string temp_Location;
	double temp_Latitude;
	double temp_Longitude;
	string temp_SSID;
	//empty list
	if(NULL==head)
	{
		return 0;
	}
	current=head;
	//current points to where head points to
	while(current!=NULL)
	{
		//use get method, to find the member variable of this data
		current->data.get(temp_ObjectID,temp_Boro,temp_Type,temp_Provider,temp_Name,temp_Location,temp_Latitude,temp_Longitude,temp_SSID);
		//it is within the distance
		//cout<<current->data.haversine(temp_Latitude,temp_Longitude,latitude,longitude)<<endl;
		//cout<<"distance equal to "<<current->data.haversine(temp_Latitude,temp_Longitude,latitude,longitude)<<"and two points dis"<<distance<<endl;
		if(current->data.haversine(temp_Latitude,temp_Longitude,latitude,longitude)<=distance)
		{
			//we print out the objectid number of this object at this position
			current->data.print_obejctid(os);
			//move the pointer to next, we can search the whole data set.
			current=current->next;
			
			
		}
		else//not within the distance
		{
			//search next one
			current=current->next;
		}

		
	}
	return 0;

}
template<class T>
int Sortedlist<T>:: make_empty()
{
	Node<T>* current;
	//make sure the list is not empty, if the list is not empty, set current to the one after head node
	//and delete head node, and set head equal to the current which is the one originally after head node.
	while(head!=NULL)
	{
		current=head->next;
		delete head;
		head=current;
		count++;
	}
	return count;
}
template<class T>
int Sortedlist<T>:: get_size()
{
	return size;
}


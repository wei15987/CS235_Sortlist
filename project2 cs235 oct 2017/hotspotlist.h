/*******************************************************************************
  Title          : hotspotlist.h
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Interface to the Hotspotlist  class
  Purpose        : To provide methods for storing records of hotspot into the hotspot list
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__


#include "hotspot.h"
#include "sortedlist.h"
#include "command.h"
#include <string>
#include <iostream>
using namespace std;

class Hotspotlist
{
public:
	Hotspotlist();//default constructor
	
	int write(ostream & os);//print function

	int insert(const Hotspot & Hspot);//insert function

	//int insert(const Hotspotlist &hlist,bool isSorted);

	int remove(int ObjectId);//delete function

	int get_size();//to get the size

	int retrieve(int ObjectId,Hotspot &Hspot);//to retrieve function

	int make_empty();//to make it empty

	void save_to_linkedlist(string line);//save the record into linked list

	void find(int ObjectId, ostream & os);//find specific object id, and print it out

	void getid_distance(double latitude,double longitude,double distance,ostream &os);


private:
	Sortedlist<Hotspot> hotspotlist;//by declare it with template, it has access to template class
	int size;
};







#endif /*__HOTSPOTLIST_H__*/
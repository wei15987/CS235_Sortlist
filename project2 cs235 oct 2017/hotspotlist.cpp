/*******************************************************************************
  Title          : hotspot.cpp
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Implementation to the hotspotlist class
  Purpose        : To provide methods to one hotspotlist with all records.
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#include "hotspot.h"
#include "sortedlist.h"
#include "command.h"
#include "hotspotlist.h"
#include <string>
#include <iostream>

using namespace std;

Hotspotlist::Hotspotlist()
{
	//default constructor
}

int Hotspotlist:: write(ostream & os)
{
	//it has access to the template class, so call the function from the template class, it is print function
	return hotspotlist.write(os);
}

int Hotspotlist:: insert(const Hotspot & Hspot)
{
	//call the insert function from the template class
	return hotspotlist.insert(Hspot);
}

/*int Hotspotlist::insert(const Hotspotlist &hlist,bool isSorted)
{


}*/
//call the delete function
int Hotspotlist::remove(int ObjectId)
{
	//create a temporary hotspot object
	Hotspot temp;
	//retrieve the data with specific object id
	retrieve(ObjectId,temp);
	return hotspotlist.remove(temp);
}
int Hotspotlist::get_size()
{
	//get size
	return hotspotlist.get_size();
}
int Hotspotlist::retrieve(int ObjectId,Hotspot &Hspot)
{
	//retrieve function 
	return hotspotlist.retrieve(ObjectId,Hspot);
}
int Hotspotlist::make_empty()
{
	//make the list empty
	return hotspotlist.make_empty();
}
void Hotspotlist::getid_distance(double latitude,double longitude,double distance,ostream &os)
{
	hotspotlist.find_distance(latitude,longitude,distance,os);

}
void Hotspotlist::find(int ObjectId,ostream &os)
{
	//to find the specifc objectid,and print it out
	Hotspot temp;
	retrieve(ObjectId,temp);
	temp.print(os);
}
void Hotspotlist::save_to_linkedlist(string line)
{
	//save the data into hotspotlist.
	Hotspot temp(line);
	insert(temp);

}
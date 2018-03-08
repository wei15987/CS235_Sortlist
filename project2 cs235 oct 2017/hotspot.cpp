/*******************************************************************************
  Title          : hotspot.cpp
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Implementation to the hotspot class
  Purpose        : To provide methods to one hotspot record at a time, and save it into the hotspot list.
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#include "hotspot.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>


using namespace std;

Hotspot::Hotspot()
{
	//default constructor
}
//constructor, but use to convert the string into specific type
Hotspot::Hotspot(const string line)
{
	//set a array with string type
	string word[9];
	stringstream geek(line);
	//convert the string to these object types
	string Boro,Type,Provider,Name,Location,SSID;
	int ObjectId;
	double Latitude,Longitude;
	//for loop to let array with word string get these values
	for(int i=0;i<9;i++)
	{
		getline(geek,word[i],',');
	}
	stringstream num_ObjectID(word[0]);
	num_ObjectID>>ObjectId;
	Boro=word[1];
	Type=word[2];
	Provider=word[3];
	Name=word[4];
	Location=word[5];
	stringstream num_Latitude(word[6]);
	num_Latitude>>Latitude;
	stringstream num_Longitude(word[7]);
	num_Longitude>>Longitude;
	SSID=word[8];
	//call the set function, assign this value into the private member values
	set(ObjectId,Boro,Type,Provider,Name,Location,Latitude,Longitude,SSID);
}
Hotspot::Hotspot(const Hotspot &htspot)
{
	//copy constructor
	ht_ObjectId=htspot.ht_ObjectId;
	ht_Boro=htspot.ht_Boro;
	ht_Type=htspot.ht_Type;
	ht_Provider=htspot.ht_Provider;
	ht_Name=htspot.ht_Name;
	ht_Location=htspot.ht_Location;
	ht_Latitude=htspot.ht_Latitude;
	ht_Longitude=htspot.ht_Longitude;
	ht_SSID=htspot.ht_SSID;
}
Hotspot::Hotspot(int ObjectId,string Boro, string Type, string Provider, string Name, string Location, double Latitude, double Longitude, string SSID)
{
	//set(ObjectId,Boro,Type,Provider,Name,Location,Latitude,Longitude,SSID);
}
void Hotspot:: set(int ObjectId,string Boro, string Type, string Provider, string Name, string Location, double Latitude, double Longitude, string SSID)
{
	//assign this value into the private member values
	ht_ObjectId=ObjectId;
	ht_Boro=Boro;
	ht_Type=Type;
	ht_Provider=Provider;
	ht_Name=Name;
	ht_Location=Location;
	ht_Latitude=Latitude;
	ht_Longitude=Longitude;
	ht_SSID=SSID;


}
void Hotspot:: get(int &ObjectId,string &Boro, string &Type, string &Provider, string &Name, string &Location, double &Latitude, double &Longitude, string &SSID)
{
	//get the private member values for compare etc...
	ObjectId=ht_ObjectId;
	Boro=ht_Boro;
	Type=ht_Type;
	Provider=ht_Provider;
	Name=ht_Name;
	Location=ht_Location;
	Latitude=ht_Latitude;
	Longitude=ht_Longitude;
	SSID=ht_SSID;


}
void Hotspot::print(ostream & s)
{
	//print out the private member values
	s<<ht_ObjectId<<','<<ht_Boro<<','<<ht_Type<<','<<ht_Provider<<','<<ht_Name<<','<<ht_Location<<','<<ht_Latitude<<','<<ht_Longitude<<','<<ht_SSID<<endl;
}
/*
void Hotspot::test()
{
	cout<<ht_ObjectId<<','<<ht_Boro<<','<<ht_Type<<','<<ht_Provider<<','<<ht_Name<<','<<ht_Location<<','<<ht_Latitude<<','<<ht_Longitude<<','<<ht_SSID<<endl;
}
*/
void Hotspot::print_obejctid(ostream &os)
{
	os<<ht_ObjectId<<endl;
}

double Hotspot::haversine(double lat1, double lon1, double lat2, double lon2)
{
	const double R = 6372.8;
	const double TO_RAD= M_PI/180.0;
	lat1 = TO_RAD * lat1;
	lat2 = TO_RAD * lat2;
	double dLat = (lat2-lat1)/2;
	double dLon = (lon2-lon1)/2;
	double a = sin(dLat);
	double b = sin(dLon);
	//it returns the distance
	return 2*R*asin(sqrt(a*a + cos(lat1)*cos(lat2)*b*b));
}

//overload these operators, so we can compare with two class objects

bool operator <	(const Hotspot &lt, const Hotspot &rt)
{
	return lt.ht_ObjectId<rt.ht_ObjectId;
	
}
bool operator == (const Hotspot &lt, const Hotspot &rt)
{
	return lt.ht_ObjectId==rt.ht_ObjectId;

}
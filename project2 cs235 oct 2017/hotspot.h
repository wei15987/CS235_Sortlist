/*******************************************************************************
  Title          : hotspot.h
  Author         : Wei Lian
  Created on     : October 26, 2017
  Description    : Interface to the Hotspot class
  Purpose        : To provide methods to one hotspot record at a time, and save it into the hotspot list
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__


#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

class Hotspot
{
public:
	//Default constructor; fills fields with zeros or null strings
	Hotspot();

	//Constructor that creates Hotspot object from a hotspot file text line
	Hotspot(const string line);

	//copy constructor
	Hotspot(const Hotspot & htspot);

	//Constructor to create a hotspot object from nine separate data values
	Hotspot(int ObjectId,string Boro, string Type, string Provider, string Name, string Location, double Latitude, double Longitude, string SSID);

	//Sets all nine data members
	void set(int ObjectId,string Boro, string Type, string Provider, string Name, string Location, double Latitude, double Longitude, string SSID);

	//Gets all nine data members
	void get(int &ObjectId,string &Boro, string &Type, string &Provider, string &Name, string &Location, double &Latitude, double &Longitude, string &SSID);

	/** print() - prints the hotspot data onto the given ostream
	 * @param ostream s [inout] ostream opened for writing
	 * @pre the object has valid data
	 * @post if the object has valid data, then it is written to ostream 
	 *       in CSV format and the ostream is updated
	 */
	void print(ostream & s);

	void print_obejctid(ostream &os);//print out the object id.


	double haversine(double lat1, double lon1, double lat2, double lon2);

	//void test();

	/** Two friend comparision operators:
	* bool operator < (lt,rt) is true if and only if:
	*   lt.ObjectID<rt.ObjectID
	* bool operator == (lt, rt) i true if and only if:
	*   lt.ObjectID == rt.ObjectID
	*/
	friend bool operator <	(const Hotspot &lt, const Hotspot &rt);
	friend bool operator ==	 (const Hotspot &lt, const Hotspot &rt);
private:
	int ht_ObjectId;
	string ht_Boro;
	string ht_Type;
	string ht_Provider;
	string ht_Name;
	string ht_Location;
	double ht_Latitude;
	double ht_Longitude;
	string ht_SSID;

};



#endif /*__HOTSPOT_H__*/
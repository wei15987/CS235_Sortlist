/*******************************************************************************
  Title          : main.cpp
  Author         : Wei Lian
  Created on     : october 26, 2017
  Description    : the main.cpp
  Purpose        : by passing three arguments in command line, it will read files given by users, and write files to the name given by users.
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "command.h"
#include "hotspotlist.h"


using namespace std;


//count how many arguments, and store arguments.
int main(int argc, char *argv[])
{
	string line,line1;
	Hotspotlist hlist;
	//declare command object
	Command command;
	//set this value for command object to get_arg
	string fromfile,tofile,ObjectIDstr;
	double latitude,longitude,distance;
	bool result;
	int ObjectID;
	//if there is not three arguments, pop error message.
	if(argc !=3)
	{
		cerr<<"must enter three argument"<<endl;
	}
	else
	{
		ifstream file(argv[1]),file1(argv[2]);
		//if there is error for opening file, tell users which one can't be open.
		if (!file.is_open())
		{
			cerr<<argv[1]<<" "<<"can not be open "<<endl;//csv file
		}
		//if there is error for opening file, tell users which one can't be open.
		else if(!file1.is_open())
		{
			cerr<<argv[2]<<" "<<"can not be open "<<endl;//command file
		}
		else
		{
			//while not end of the file
			while(!file.eof())
			{
				while(getline(file,line))
				{
					//it gets the data line by line, and save it to linked list
					hlist.save_to_linkedlist(line);
				}
			}
			while(!file1.eof())
			{
				//if the command was initialized to something
				if(command.get_next(file1)==true)
				{
					if(command.type_of()==0)//the command is write_cmd
					{
						//assign parameters with the values from the object
						command.get_args(fromfile,tofile,latitude,longitude,distance,result);
						//if the parameters are assigned with values. in this case result should not be false
						if(result!=false)
						{
							//open up the write to file
							ofstream write_out(tofile.c_str());
							//error message
							if(!write_out.is_open())
							{
								cerr<<tofile<<" "<<"can not be open"<<endl;
							}
							else//the file is open to write
							{
								//close the file after finish writing
								hlist.write(write_out);
								write_out.close();
							}
						}
						//else the values are not valid
					}
					else if(command.type_of()==1)//the command is save_by_id_cmd
					{
						//assign parameters with the values from the object
						command.get_args(fromfile,tofile,latitude,longitude,distance,result);
						if(result!=false)
						{
							ifstream read_file(fromfile.c_str());
							ofstream write_out(tofile.c_str());
							//if the parameters are assigned with values. in this case result should not be false
							if(!read_file.is_open())
							{
								//error message
								cerr<<fromfile<<" "<<"can not be open"<<endl;
							}
							else if(!write_out.is_open())
							{
								//error message
								cerr<<tofile<<" "<<"can not be open"<<endl;
							}
							else//both files are open
							{
								while(!read_file.eof())
								{
									//reads the file line by line,and save it to string
									while(getline(read_file,ObjectIDstr))
									{
										//convert string to int type
										stringstream geek(ObjectIDstr);
										geek>>ObjectID;
										//call the find function to find the objectid and print it out
										hlist.find(ObjectID,write_out);
									}
								}
								read_file.close();
								write_out.close();
							}
						}
					}
					else if(command.type_of()==2)//the command is save_by_loc_cmd;
					{
						//assign parameters with the values from the object
						command.get_args(fromfile,tofile,latitude,longitude,distance,result);
						//if the parameters are assigned with values. in this case result should not be false
						if(result!=false)
						{
							ofstream write_out(tofile.c_str());
							if(!write_out.is_open())
							{
								//error message
								cerr<<tofile<<" "<<"can not be open"<<endl;
							}
							else
							{
								//cout<<"latitude is "<<latitude<<"longitude is "<<longitude<<"distance is :"<<distance<<"to file is "<<tofile<<endl;
								hlist.getid_distance(latitude,longitude,distance,write_out);
								write_out.close();
							}
						}

					}
					
					
					else if(command.type_of()==3)//insert_cmd
					{
						//assign parameters with the values from the object
						command.get_args(fromfile,tofile,latitude,longitude,distance,result);
						//if the parameters are assigned with values. in this case result should not be false
						if(result!=false)
						{
							ifstream read_file(fromfile.c_str());
							if(!read_file.is_open())
							{
								//error message
								cerr<<fromfile<<" "<<"can not be open"<<endl;
							}
							else
							{
								while(!read_file.eof())
								{
									while(getline(read_file,line1))
									{
										//insert the data to the linked list
										hlist.save_to_linkedlist(line1);
									}
								}
								read_file.close();
							}
						}
					}
					else if(command.type_of()==4)//delete_by_id_cmd
					{
						//assign parameters with the values from the object
						command.get_args(fromfile,tofile,latitude,longitude,distance,result);
						//if the parameters are assigned with values. in this case result should not be false
						if(result!=false)
						{
							ifstream read_file(fromfile.c_str());
							if(!read_file.is_open())
							{
								//error message
								cerr<<fromfile<<" "<<"can not be open"<<endl;
							}
							else
							{
								while(!read_file.eof())
								{
									//get the data line by line, assign it to string
									while(getline(read_file,ObjectIDstr))
									{
										//convert string to int type
										stringstream geek(ObjectIDstr);
										geek>>ObjectID;
										//delete the data with the objectid
										hlist.remove(ObjectID);
									}
								}
								read_file.close();
							}
						}
					}
					//else are bad commands and null
				}
				//else the command was not initialized with valid commands
			}
			file.close();
			file1.close();
		}
	}



	return 0;

}

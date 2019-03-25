/*Project EOP Carpool management system
  	-Muhammad Syafiq bin Mohd Faudzy 1623765
	-Nik Ahmad Faiz bin Mohd Fauzi 1623399
	-Muhammad Laziem bin Shafie 1621781
	-Omar Omarov G1411499*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "CarpoolExtern.h"

using namespace std;

void disp();			//user interface
void loginui();			//user interface for login
void driver();			//login as driver
void userui();			//login as passenger
void userdisp(int*);	//user interface for user's profile
void invalid();			//user interface
void design();			//user interface
void wait();			//user interface

data trip[size];		//to store trip data
data1 user[size];		//to store user's data
data3 history[size];	//to store book's history
int userindicator;		//to check indicate updating username
string currentuser;		//current user logging in purpose
string newuser;			//assign updated username to newuser
int i,j;


int main()
{
	system("title Carpool Nougat");
	system ("color E0");
	int x=0,y=0;
	char opt;
	data1 userstruct;
	ifstream userdata;
	userdata.open("Userdata.dat");	//To access userdata file
	while(userdata>>userstruct.username>>userstruct.password>>userstruct.phone>>userstruct.role)
	{
		user[y].username=userstruct.username;
		user[y].password=userstruct.password;
		user[y].phone=userstruct.phone;
		user[y].role=userstruct.role;
		y++;
	}
	userdata.close();
	do{
		opt='\0';
		disp();		//call function display
		cin >> opt;
	
		while(opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B')
		{
			system("cls");
		    invalid(); 
			disp();
			cin >> opt;	
		}
	
		switch(opt)
		{
			case 'a':
			case 'A':  loginui(); break;		////call function loginui
			case 'b':
			case 'B':  x=1;break;
		}
		
	}while(x!=1);	//loop will break if x=1
	credit();		//call function credit
	system("pause>null");
	
	return 0;

}
void disp()   //DISPLAY
{
	system("cls");
	design();
	cout << "\t\t\tA.LOGIN\n"
	 	 << "\t\t\tB.EXIT\n\n"
	 	 << "\t\t\tEnter Your Option : ";
}

void loginui() //LOGIN user interface
{
	char log;

	system("cls");
	design();
	cout << "\t\t\tLOGIN AS\n\n"
		 << "\t\t\tA.Driver" << endl
		 << "\t\t\tB.Passenger" << endl
	  	 << "\t\t\tC.Back\n" << endl
		 << "\t\t\tEnter Your Option : ";
	cin >> log;

	while(log != 'a' && log != 'A' && log != 'b' && log != 'B' && log != 'c' && log != 'C')
	{
	
		system("cls");
		invalid();
		design();
		cout << "\t\t\tLOGIN AS\n\n"
			 << "\t\t\tA.Driver" << endl
			 << "\t\t\tB.Passenger" << endl
		  	 << "\t\t\tC.Back\n" << endl
			 << "\t\t\tEnter Your Option : ";
		cin >> log;
	
	}
	switch(log)
			{
				case 'a':
				case 'A': driver(); break;		//call function driver
				case 'b':  
				case 'B': userui(); break;		//call function userui
				case 'c':
				case 'C':break;
			}

}

void driver() //login as driver
{
	int x=0;
	int indicator;
	char opt;
	system("cls");
	design();
	cout << "\t\t\tA.LOGIN" << endl
		 << "\t\t\tB.CREATE NEW ID" << endl
		 << "\t\t\tC.Back\n" << endl
		 << "\t\t\tEnter Your Option : ";
	cin >> opt;


	while(opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B' && opt != 'c' && opt != 'C')
	{
	
		system("cls");
		invalid();
		design();
		cout << "\t\t\tA.LOGIN" << endl
			 << "\t\t\tB.CREATE NEW ID" << endl
			 << "\t\t\tC.Back\n" << endl
			 << "\t\t\tEnter Your Option : ";
		cin >> opt;
	}
	switch(opt)
	{
		case 'a' :
		case 'A' :
				
				indicator=login();		//call function login
				if(indicator!=1)
				{
					for(i=0;i<size;i++)
			        {
			            if(user[i].username==currentuser)	//check the currentuser
			            {
			                user[i].role="Driver";			//assign to driver
			            }
			        }
			        do{
			        	for(i=0;i<size;i++)
				        {
				            if(user[i].username==currentuser)
				            {
				            	userdisp(&i);			//call userdisp
				            }
				        }
				        
						displayfordriver();			//call displayfordriver
						cout<< "\n\n\t\tA.Update Trip " << endl
							 << "\t\tB.Publish Trip" << endl
							 << "\t\tC.Update user" << endl
							 << "\t\tD.DELETE Trip" << endl
							 << "\t\tE.Logout" << endl
							 << "\t\tEnter Your Option : " ;	//user interface
						cin >> opt;
						while(opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B' && opt != 'c' && opt != 'C'&& opt != 'd' && opt != 'D'&& opt != 'e' && opt != 'E')
						{
						
							system("cls");
							invalid();
							for(i=0;i<size;i++)
				        	{
				            	if(user[i].username==currentuser)
				            	{
				            		userdisp(&i);
				           		 }
				        	}	
				        	
				        	displayfordriver();
							cout << "\n\n\t\tA.Update Trip " << endl
								 << "\t\tB.Publish Trip" << endl
								 << "\t\tC.Update user" << endl
								 << "\t\tD.DELETE Trip" << endl
								 << "\t\tE.Logout" << endl
								 << "\t\tEnter Your Option : " ;
							cin >> opt;
						}
						if(opt=='a' || opt=='A')
							updatetrip();						//call function updatetrip
						else if(opt == 'b' || opt == 'B')
							createtrip();						//call function createtrip
						else if(opt == 'c' || opt == 'C'){
							updateuser();						//call function updateuser
							if(userindicator==1){				//check if username was updated 
								for(i=0;i<size;i++)
					        	{
					        		
				        			if(trip[i].driver==currentuser && trip[i].driver!="")
					            	{
					            		
					            			trip[i].driver=newuser;
					           		 }	
					        	}	
					        	currentuser=newuser;
							}
							
						}
							
						else if(opt == 'd' || opt == 'D')
							deletetrip();			//call function deletetrip
						else
							x=1;
						
					}while(x!=1);	//break if x=1;
				}
				break;
		case 'b' :
		case 'B' :
			for(i=0;i<size;i++)
			{
				if(user[i].role=="")
				{
					user[i].role="Driver";
					break;
				}
			}
			regist();
			wait();
			
			break;
		case 'c':case 'C':loginui();break;		//call	loginui back
		
	}
	
	
}
void userui() //login as passenger
{
	char opt;
	int indicator;
	int x=0;

	system("cls");
		design();
		cout << "\t\t\tA.LOGIN" << endl
		     << "\t\t\tB.CREATE NEW USER" << endl
		     << "\t\t\tC.Back\n" << endl
	     	 << "\t\t\tEnter Your Option : ";
		cin >> opt;

	while(opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B' && opt != 'c' && opt != 'C')
	{
	
		system("cls");
		invalid();
		design();
		cout << "\t\t\tA.LOGIN" << endl
		     << "\t\t\tB.CREATE NEW USER\n" << endl
		     << "\t\t\tC.Back\n" << endl
	     	 << "\t\t\tEnter Your Option : ";
		cin >> opt;
	}

	switch(opt)
	{
		case 'a':case 'A':indicator=login();		//call function login
							for(i=0;i<size;i++)
					        {
					            if(user[i].username==currentuser)		//check the currentuser
					            {
					                user[i].role="Passenger";			//assign to passenger
					            }
					        }
					        if(indicator!=1)
					        {
					        	do{
						        	for(i=0;i<size;i++)
							        {
							            if(user[i].username==currentuser)
							            {
							            	userdisp(&i);
							         	}
							        }
									cout << "\n\t\tA.Update Information " << endl
										 << "\t\tB.Join a trip" << endl
										 << "\t\tC.Book History" << endl
										 << "\t\tD.Logout"<<endl
										 << "\t\tEnter Your Option: " ;
									cin >> opt;
									while(opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B'&& opt != 'c' && opt != 'C'&& opt != 'd' && opt != 'D')
									{
									
										system("cls"); 
										invalid();
										
										for(i=0;i<size;i++)
							        	{
							            	if(user[i].username==currentuser)
							            	{
							                 userdisp(&i);		////call function userdisp and sending index number [i]
							           		 }
							        	}
												
										cout  << "\n\t\tA.Update Information " << endl
										 	  << "\t\tB.Join a trip" << endl
											  << "\t\tC.Book History" << endl
											  << "\t\tD.Logout"<<endl
											  << "\t\tEnter Your Option : " ;
										cin >> opt;
									}
									if(opt=='a' || opt=='A'){
										updateuser();			//call function updateuser
										if(userindicator==1)	//check if username was updated
												currentuser=newuser;
											
									}
										
									else if(opt=='b' || opt=='B')
										booktrip();						//call function booktrip
									else if(opt=='c' || opt=='C')
										custhistory();					////call function custhistory
									else
										x=1;				
								}while(x!=1);					//break if x=1
							}	
					break;
		case 'b':case 'B': for(i=0;i<size;i++)
							{
								if(user[i].role=="")
								{
									user[i].role="Passenger";
									break;
								}
							}
							regist();			////call function regist
							wait();
							break;
		case 'c':case 'C':loginui();break;			//call back funtion loginui
	}
}

void userdisp(int *i)		//user interface for user's profile
{
	cout << setiosflags(ios::left) << endl;
				            	cout << "\n\t\t+================================+" << endl
			 	 					 << "\t\t|  Username:     " <<setw(15) << user[*i].username  << " |" << endl;
			 	 					if(user[*i].role=="Passenger")
			 	 				cout << "\t\t|  Current Role: " <<user[*i].role << "       |" << endl;
			 	 					else
			 	 				cout << "\t\t|  Current Role: " <<user[*i].role << "          |" << endl;
			 	 				
			 	 				cout << "\t\t|  Phone number: " << setw(11) <<user[*i].phone << "     |" << endl
			     					 << "\t\t+================================+" << endl;
	
}

void design()		//userinterface
{
	cout  << "\n\n\t\t\t+====================+" << endl
	 	  << "\t\t\t|\tCARPOOL\t     |" << endl
	      << "\t\t\t+====================+"
	      << "\n\n\n"	;
}

void invalid()		//user interface
{
	system("cls");
	system("color C0");
	cout  << "\n\n\n\n\n\t\t\t+============================+" << endl
	 	  << "\t\t\t|\tINVALID INPUT\t     |" << endl
	      << "\t\t\t+============================+"
	      << "\n\n\n"	;
	Sleep(1000);
	system("cls");
	system("color E0");
	      
}

void wait()	//user interface
{
	cout << "\n\n\t\tPlease wait for a moment" << endl;
	Sleep(2000);
	cout << "\t\tThank you for your registeration..please log in back" << endl;
	Sleep(1500);
	system("cls");
}


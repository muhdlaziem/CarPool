/*Project EOP Carpool management system
  	-Muhammad Syafiq bin Mohd Faudzy 1623765
	-Nik Ahmad Faiz bin Mohd Fauzi 1623399
	-Muhammad Laziem bin Shafie 1621781
	-Omar Omarov G1411499*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

void createtrip();					//To create trip
int generate();						//To generate unique trip id
void regist();						//To register user
int login();						//to login
void booktrip();					//to book a trip
void updatetrip();					//updating trip trip
void displaydest();					//dispalying trip's data only for passenger
void displayfordriver();			//dispalying trip's data only for driver
void calculate(int*,int*);			//calculate price
void updateuser();					//update user data
void deletetrip();					//delete trip
void custhistory();					//view customer history
void credit();
extern void userdisp(int*);
extern void invalid();
string time();

 struct data
{
	int id;
	char type;
	string desc;
	string car;
	int seat;
	double price;
	string driver;
};
 struct data1
{
	string username;
	string password;
	string role;
	string phone;
};
struct data3
{
	string tripdriver;
	string cust;
	string destination;
	string driverphone;
	int seatbooked;
	double totalprice;
	string timedate;
	
};

const int size=10;

extern data trip[size];
extern data1 user[size];
extern data3 history[size];

extern string currentuser;
extern string newuser;
extern int i,j;
extern int userindicator;


void regist()
{
	ofstream userdata;
	system("cls");
	cout<<"\n\n\t\tEnter new username: ";
	for(i=0;i<size;i++)
	{
		if(user[i].username=="")			//check if there is an empty space in array struct
		{
			
			cin>>user[i].username;
			for(j=0;j<size;j++)
			{
				if(user[i].username==user[j].username && i!=j)
				{
					cout<<"\t\tThis username already exists. \n\n\t\tPlease enter again: ";
					cin>>user[i].username;j=-1;
				}
			}
			break;
		}
	}
	cin.ignore();
	cout<<"\t\tEnter password: ";
	cin>>user[i].password;

	cout<<"\t\tEnter phone number: ";
	cin>>user[i].phone;
	userdata.open("Userdata.dat");		//store the user data to Userdata.dat
	for(i=0;i<size;i++)
	{
		userdata << user[i].username << " " << user[i].password << " " <<user[i].phone << " " <<user[i].role << endl;
	}
	userdata.close();
	
	
}
void createtrip()
{
	char answer;
	system("cls");
	do
	{
		cout<<"\n\n\t\tType of trip (S - Short OR L - Long): ";
		for(i=0;i<size;i++)
		{
			if(trip[i].type=='\0')	//check for empty array struct
			{
				cin>>trip[i].type;
				while(trip[i].type!='S'&& trip[i].type!='s' && trip[i].type!='L' && trip[i].type!='l')
				{
					invalid();
					cout<<"\n\n\t\tType of trip (S - Short OR L - Long): ";
					cout<<"\n\n\t\tInvalid input.\n\t\tPlease enter again: ";
					cin>>trip[i].type;
				}
				break;
	
			}
		}
		cin.ignore();
		trip[i].id=generate();
		cout<<"\n\t\tEnter the description of your vehicle: ";
		getline(cin,trip[i].car);
		cout<<"\n\t\tEnter your destination: ";
		getline(cin,trip[i].desc);
		cout<<"\n\t\tEnter seats available: ";
		cin>>trip[i].seat;
		cout<<"\n\t\tEnter the price(per trip): RM ";
		cin>>trip[i].price;
		trip[i].driver=currentuser;
		cout<<"\n\t\tDo you want add more trip?(Y or N): ";
		cin>>answer;
		while(answer!='y' && answer!='Y' && answer!='n' && answer!='N')
		{
			invalid();
			cout<<"\n\n\n\t\tInvalid input.\n\t\tDo you want add morfe trip ? (Y or N): ?";
			cin>>answer;
		}
		system("cls");
	}while(answer=='y' || answer=='Y');
	
}
int generate()
{
	int id;
	srand (time(NULL));			//generate
	id=rand() % (100 +900);
	
	return id;			//return the value
}
int login()
{
	int x,y=0,z=0,count=0;
	int indicator;
	char answer;
	string userinput,userpass;
	bool pot1,pot2;

	system("cls");
	cout << "\n\n\t\tEnter username: " ;
	cin >> userinput;

	for(i=0;i<size;i++)
		{
			pot1 = userinput.compare(user[i].username);	//compare userinput with our data

			if(pot1 == 0)
			{
				x = i;
				break;
			}
		}

		while (pot1 != 0)
		{
			system("cls");
			cout << "\n\t\tInvalid username\n"
				 <<"\t\tThere is no username : (" << userinput << ")\n\n"
				 << "\t\tRe-enter username :";
			cin >> userinput;

			for(i=0;i<size;i++)
			{
				pot1 = userinput.compare(user[i].username);
				if(pot1 == 0)
				{
					x = i;count--;
					break;
				}
			}
			count++;		//to count wrong entries
			if(count>=2)
			{
				cout<<"\t\tYou have entered 3 times wrong\n\n";
				system("pause>null");
				system("cls");
				z=1;indicator=1;break;
			}
		}
		count=0;
		if(z!=1)
		{
			cout << "\t\tEnter password : "; //Check Password
			cin >> userpass;
	
			pot2 = userpass.compare(user[x].password);
	
			 while (pot2 != 0)
			 {
			 	system("cls");
			 	cout << "\n\n\t\tInvalid password \n "
			 	     << "\n\t\tUsername : (" << user[x].username << ")" 
				     << "\n\t\tRe-enter password : ";
	
				cin >> userpass;
	
				pot2 = userpass.compare(user[x].password);
				if(pot2==0)
					count--;
				count++;				//to count wrong entries
				if(count>=2)
				{
					cout<<"\t\tYou have entered 3 times wrong\n\n";
					system("pause>null");
					system("cls");
					y=1;indicator=1;break;
				}	
			 }
		}
		if(indicator!=1)
		 	currentuser=user[x].username;

		 if(pot2==0 && y!=1 && indicator !=1)
		 {
		 	system("cls");
		 	cout <<"\n\n\t\tWelcome " <<currentuser <<" to Your Profile " << endl;
		 }
	return indicator;		//return a value to indicate the user succesfully login or not
}
void booktrip()
{
	int x=-1,y=0,z,userseat,back=0;
	double total;
	int userdest;
	char input,opt;
	do{
		back=0;
		system("cls");
		cout<<"\n\n";
		displaydest();		//call function displaydest
		cout<<"\n\n\t\tA.Book a Trip\n";
		cout<<"\t\tB.Back\n";
		cout<<"\t\tEnter Option: ";
		cin>>opt;
		system("cls");
		while(opt!='a' && opt!='A' && opt!='b' && opt!='B')
		{
			invalid();
			displaydest();			//call function displaydest
			cout<<"\n\n\t\tA.Book a Trip\n";
			cout<<"\t\tB.Back\n";
			cout<<"\t\tEnter Option: ";
			cin>>opt;
			system("cls");
			
		}
		switch(opt)
		{
			case 'a':case 'A':x=-1;z=0;y=0;
										displaydest();			//call function displaydest
								cout << "\n\t\tPlease enter the trip ID : ";
								cin >> userdest;
						
								for(i=0;i<size;i++)
								{
									if(userdest==trip[i].id)		//check the existing trip
									{
										x=i;
										break;
									}
								}
								
								while(x == -1)
								{
									y++;
									system("cls");
									displaydest();
									cout << "\n\n\t\tInvalid trip\n"
										 << "\t\tPlease re-enter : ";
									cin >> userdest;
						
									for(i=0;i<size;i++)
									{
										if(userdest==trip[i].id)
										{
											x=i;y--;
											break;
										}
									}
									if(y>=2)
									{
										z=1;break;
									}
											
								}
								if(z!=1)
								{
									cout << "\n\t\tEnter the number of seat(s) to reserve : ";
									cin >> userseat;
							
									while(userseat<=0)
									{
										cout << "\n\t\tInvalid number of seat(s)"
											 <<"\n\t\tPlease re-enter : ";
										cin >> userseat;
									}
									if(trip[x].seat>=userseat)			//check the existing seats
									{
										trip[x].seat -= userseat;
										calculate(&x,&userseat);			//call function calculate
									}	
									else if (trip[x].seat<userseat)
									{
										cout << "\n\t\tSeat(s) is not available ";
									}
								}break;
			case'b':case'B': back=1;break;	
			default:break;		
		}
		if(back!=1)
		{
			cout << "\n\t\tDo you want to continue booking ? (Y or N) : ";
			cin >> input;
			while(input!='y' && input!='Y' && input!='n' && input!='N')
			{
				cout<<"\n\t\tInvalid input. Do you want to continue booking?(Y or N): ?";
				cin>>input;
			}
		}
		if(back==1)
			break;
		
		
		system("cls");

	}while(input == 'Y' || input =='y');

}
void updatetrip()
{
	int code,y=0,x,z=0;
	char option,answer;
	system("cls");
	cout<<"\n\n\t\tUpdating your Trip Data\n\n";
	displayfordriver();
	cout<<"\n\t\tEnter your Trip ID: ";
	cin>>code;
	for(i=0;i<size;i++)
	{
		if(code==trip[i].id)			//check the existing trip
			{
					x=i;
					y=1;
					break;
			}			
	}
	while (y!=1)
	{
		cout << "\n\n\t\tTrip does not exist\n"
			 <<"\t\tThere is no trip with ID : (" << code << ")\n\n"
			 << "\t\tRe-enter trip ID :";
		cin >> code;

		for(i=0;i<size;i++)
		{
			if(code==trip[i].id)
			{
					x=i;
					y=1;z--;
					break;
			}
		}
		z++;
		if(z>=2)
		{
			cout<<"\t\tYou have entered 3 times wrong\n\n";
			system("pause>null");
			system("cls");break;
		}
	}
	system("cls");
	if(y==1)
	{
		do
		{
			displayfordriver();
			cout<<"\n\t\tChoose the Data you want to update: \n\n";
			cout<<"\t\tA.Type\n"
				<<"\t\tB.Destination\n"
				<<"\t\tC.Car\n"
				<<"\t\tD.Seat(s)\n"
				<<"\t\tE.Price per seat (RM)\n\n";
			cout<<"\t\tEnter Option: ";
			cin>>option;
			while (option!='a' && option !='A' && option!='b' && option !='B' && option!='c' && option !='C'
					&& option!='d' && option !='D' && option!='e' && option !='E')
			{
				invalid();
				displayfordriver();
				cout<<"\n\t\tChoose the Data you want to update: \n\n";
				cout<<"\t\tA.Type\n"
					<<"\t\tB.Destination\n"
					<<"\t\tC.Car\n"
					<<"\t\tD.Seat(s)\n"
					<<"\t\tE.Price per seat (RM)\n\n";
				cout<<"\t\tInvalid Option. Enter Option: ";
				cin>>option;
			}
			cin.ignore();
			switch(option)
			{
				case 'a':case 'A': system("cls");
								   displayfordriver();			//call function displayfordriver
								   cout<<"\n\n\tEnter new Type of Trip (S - Short & L - Long): ";
								   cin>>trip[x].type;
								   while(trip[x].type !='S' && trip[x].type !='s' && trip[x].type !='L' && trip[x].type !='l')
								   {
								   		invalid();
								   		displayfordriver();
								   		cout<<"\n\tInvalid input.\n\tEnter new Type of Trip (S - Short & L - Long): ";
								   		cin>>trip[x].type;
								   }break;
				case 'b':case 'B': system("cls");
								   displayfordriver();cout<<"\n\n\tEnter New Destination: ";
								   getline(cin,trip[x].desc);break;
				case 'c':case 'C': system("cls");
								   displayfordriver();cout<<"\n\n\tUpdate your car: ";
				  				   cin>>trip[x].car;break;
				case 'd':case 'D': system("cls");
								   displayfordriver();cout<<"\n\n\tUpdate number of seats:";
							       cin>>trip[x].seat;break;
				case 'e':case 'E': system("cls");
								   displayfordriver();cout<<"\n\n\tUpdate price per seat (RM): ";
								   cin>>trip[x].price;break;
			}
			cin.ignore();
			cout<<"\n\t\tDo you want to continue updating your trip?\n\n"
				<<"\t\tType 'Y' for YES and 'N' for NO: ";
			cin>>answer;
			while(answer!='y' && answer!='Y' && answer!='n' && answer!='N')
			{
				invalid();
				displayfordriver();
				cout<<"\n\t\tDo you want to continue updating your trip?\n\n";
				cout<<"\t\tInvalid input. Type 'Y' for YES and 'N' for NO: ";
				cin>>answer;
			}
		system("cls");	
		}while(answer=='Y'|| answer=='y');		
	}	
}

void updateuser()	//updating user's profile
{
	ofstream userdata;
	int x;
	char option,answer;
	system("cls");
	do{
		cout<<"\n\n\t\tUpdating user information\n\n";
		for(i=0;i<size;i++)
	    {
	        if(user[i].username==currentuser)		//check with the currentuser
	        {
	        	x=i;
	        	userdisp(&x);	
	        }
	    }
	    cout<<"\t\tChoose the information you want to update:\n\n"
	    	<<"\t\tA.User name\n"
	    	<<"\t\tB.Password\n"
	    	<<"\t\tC.Telephone Number\n\n"
	    	<<"\t\tEnter option: ";
	    cin>>option;
		while(option!='a' && option !='A' && option!='b' && option !='B' && option!='c' && option !='C')
		{	
			invalid();
			system("cls");
			cout<<"\n\t\tUpdating user information\n\n";
			for(i=0;i<size;i++)
	    	{
	        	if(user[i].username==currentuser)
	        	{	
	        		x=i;
	        		userdisp(&x); 			//call fucntion userdisp and sending index x
	       	 	}
	    	}	
			cout<<"\n\t\tChoose the information you want to update:\n\n"
		    	<<"\t\tA.User name\n"
		    	<<"\t\tB.Password\n"
		    	<<"\t\tC.Telephone Number\n\n"
		    	<<"\t\tInvalid option. Enter option: ";
		    cin>>option;
		}
		switch(option)
		{
			case 'a':case'A':system("cls");
							 cout<<"\n\t\tUpdating user information";
							 userdisp(&x);						//call fucntion userdisp and sending index x
							 userindicator=1;					//to indicate the user was updating username
							 
							 cout<<"\t\tEnter new username : ";
							 cin>>user[x].username;
							
							for(j=0;j<size;j++)
							{
								if(user[x].username==user[j].username && x!=j)
								{
									cout<<"\n\t\tThis username already exists.\n\t\tPlease enter again: ";
									cin>>user[x].username;
								}
							}
							newuser=user[x].username;		//assigining to newuser
							break;
			case 'b':case 'B':system("cls");
							  cout<<"\n\t\tUpdating user information";
							  userdisp(&x);			
							  cout<<"\t\tEnter new password: ";
							  cin>>user[x].password;
							  break;
			case 'c':case 'C':system("cls");
							  cout<<"\n\t\tUpdating user information";	
							  userdisp(&x);
			                  cout<<"\t\tEnter new telephone number: ";
							  cin>>user[x].phone;break;
								
		}
		cout<<"\n\t\tDo you want to continue updating your profile?\n"
				<<"\t\tType 'Y' for YES and 'N' for NO: ";
			cin>>answer;
			while(answer!='y' && answer!='Y' && answer!='n' && answer!='N')
			{
				invalid();
				cout<<"\n\t\tDo you want to continue updating your profile?\n";
				cout<<"\t\tInvalid input. Type 'Y' for YES and 'N' for NO: ";
				cin>>answer;
			}
		system("cls");	
	}while(answer=='Y'|| answer=='y');
	
	userdata.open("Userdata.dat");		//store the user data to Userdata.dat
	for(i=0;i<size;i++)
	{
		userdata << user[i].username << " " << user[i].password << " " <<user[i].phone << " " <<user[i].role << endl;
	}
	userdata.close();
}

void displaydest()
{
	cout  << "\t\t+============================+" << endl
	 	  << "\t\t|\tTRIP AVAILABLE\t     |" << endl
	      << "\t\t+============================+" << endl;
	
		cout<<setiosflags(ios::left);
		cout<<"\n\n"<<setw(8)<<"Trip ID"<<setw(5)<<"Type"<<setw(20)<<"Destination"<<setw(10)<<"Car"<<setw(8)<<"Seat(s)"<<setw(20)<<" Price per seat (RM)"<<endl;
		cout<<setw(8)<<"-------"<<setw(5)<<"----"<<setw(20)<<"-----------"<<setw(10)<<"---"<<setw(8)<<"-------"<<setw(20)<<"-------------------"<<endl;
		cout<<setiosflags(ios::left);
		for(i=0;i<size;i++)
		{
			if(trip[i].seat>0)
			{
				cout<<setw(8)<<(*(trip + i)).id<<setw(5)<<(*(trip + i)).type
					<<setw(20)<<(*(trip + i)).desc<<setw(10)<<(*(trip + i)).car
					<<setw(8)<<(*(trip + i)).seat<<setw(20)<<(*(trip + i)).price<<endl;
			}
		}
}
void calculate(int *x,int *seat)
{
	int y=0,z=0;
	string timebooked;
	for(i=0;i<size;i++)
	{
		if(user[i].username==trip[*x].driver)
			y=i;
	}
	for(i=0;i<size;i++)
	{
		if(history[i].cust=="")
		{
			z=i;break;
		}		
	}
	system("cls");																			//user interface after booking
	cout<<"\n\n\t\tThank you riding with "<<trip[*x].driver<<" !\n\n\n";
	history[z].tripdriver=trip[*x].driver;
	cout<<"\t\tRide Details: \n\n";
	cout<<"\t\t+======================================+\n\n";
	cout<<"\t\t Total seats booked: "<<*seat<<endl;
	history[z].seatbooked=*seat;
	cout<<"\t\t Destination: "<<trip[*x].desc<<endl;
	history[z].destination=trip[*x].desc;
	cout<<"\t\t Driver's Phone Number: "<<user[y].phone<<endl;
	history[z].driverphone=user[y].phone;
	cout<<"\t\t Price: RM "<<fixed<<setprecision(2)<<(double)(*seat)*trip[*x].price<<endl;
	history[z].totalprice=(double)(*seat)*trip[*x].price;
	timebooked=time();
	history[z].timedate=timebooked;
	history[z].cust=currentuser;
	cout<<"\t\t (Time & Date) booked : "<<timebooked<<endl;
	cout <<"\n\t\t+======================================+\n\n";
	return ;
}
string time()		//to get current time
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
  string str(buffer);

  return str;
}
void deletetrip()
{
	int code,y=0,x,z=0,back=0;
	char option,answer;

	do
	{
		z=0;
		y=0;
		system("cls");
		displayfordriver();							//call fucntion displayfordriver
		cout<<"\n\n\t\tDeleting your Trip \n\n";
		cout<<"\t\tA. Delete Trip\n";
		cout<<"\t\tB. Back\n";
		cout<<"\t\tEnter Option: ";
		cin>>option;
		system("cls");
		while(option!='a' && option!='A' && option!='b' && option!='B')
		{
			invalid();
			cout<<"\n\n\t\tDeleting your Trip \n\n";
			cout<<"\t\tA. Delete Trip\n";
			cout<<"\t\tB. Back\n";
			cout<<"\t\tEnter Option: ";
			cin>>option;
			system("cls");
		}
		switch(option)
		{
			case 'a':case'A':	displayfordriver();
						
								cout<<"\n\n\tEnter your Trip ID: ";
								cin>>code;
								for(i=0;i<size;i++)
								{
									if(code==trip[i].id)				//check existing trip
										{
												x=i;
												y=1;
												break;
										}			
								}
								while (y!=1)
								{
									invalid();
									displayfordriver();
									cout << "\n\n\t\tTrip does not exist\n"
										 <<"\t\tThere is no trip with ID : (" << code << ")\n\n"
										 << "\t\tRe-enter trip ID :";
									cin >> code;
							
									for(i=0;i<size;i++)
									{
										if(code==trip[i].id)
										{
												x=i;
												y=1;
												z--;
												break;
										}	
									}
									z++;		//count user entries
									if(z>=2)
									{
										cout<<"\n\t\tYou have entered 3 times wrong";
										break;
									}
								}
								if(y==1)
								{
									trip[x].car="";
									trip[x].desc="";
									trip[x].driver="";
									trip[x].id=0;
									trip[x].price=0;
									trip[x].seat=0;
									trip[x].type='\0';
								}break;
			case'b':case'B':back=1;break;
			default:break;
		}
		if(back!=1){
			cout<<"\n\t\tDo you want to continue deleting your trip?\n"
				<<"\t\tType 'Y' for YES and 'N' for NO: ";
			cin>>answer;
			while(answer!='y' && answer!='Y' && answer!='n' && answer!='N')
			{
				cout<<"\n\t\tInvalid input. Type 'Y' for YES and 'N' for NO: ";
				cin>>answer;
			}
		}
		if(back==1)
			break;
		
	}while(answer=='Y'|| answer=='y');	
	system("cls");	
}
void displayfordriver()
{
	cout <<"\n\n";
	cout  << "\t\t+============================+" << endl
	 	  << "\t\t|\tYOUR TRIP\t     |" << endl
	      << "\t\t+============================+" << endl;
	      
	cout<<setiosflags(ios::left);
	cout<<"\n\n"<<setw(8)<<"Trip ID"<<setw(5)<<"Type"<<setw(20)<<"Destination"<<setw(10)<<"Car"<<setw(8)<<"Seat(s)"<<setw(20)<<" Price per seat (RM)"<<endl;
	cout<<setw(8)<<"-------"<<setw(5)<<"----"<<setw(20)<<"-----------"<<setw(10)<<"---"<<setw(8)<<"-------"<<setw(20)<<"-------------------"<<endl;
	cout<<setiosflags(ios::left);
	for(i=0;i<size;i++)
	{
		if(currentuser==trip[i].driver)
		{
			cout<<setw(8)<<(*(trip + i)).id<<setw(5)<<(*(trip + i)).type
				<<setw(20)<<(*(trip + i)).desc<<setw(10)<<(*(trip + i)).car
				<<setw(8)<<(*(trip + i)).seat<<setw(20)<<(*(trip + i)).price<<endl;
		}
	}
}
void custhistory()
{
	system("cls");
	for(i=0;i<size;i++)
	{
		if(history[i].cust==currentuser)
		{
			cout<<"\n\n\t\tThank you riding with "<<history[i].tripdriver<<" !\n\n\n";
			cout<<"\t\tRide Details: \n\n";
			cout<<"\t\t+======================================+\n\n";
			cout<<"\t\t Total seats booked: "<<history[i].seatbooked<<endl;
			cout<<"\t\t Destination: "<<history[i].destination<<endl;
			cout<<"\t\t Driver's Phone Number: "<<history[i].driverphone<<endl;
			cout<<"\t\t Price: RM "<<fixed<<setprecision(2)<<history[i].totalprice<<endl;
			cout<<"\t\t (Time & Date) booked : "<<history[i].timedate<<endl;
			cout <<"\n\t\t+======================================+\n\n";
		}
	}
	system("pause");
	system("cls");
}
void credit()
{
	system("cls");
	       
	cout<<"\n\n\n\n\n\n\n\t\tDeveloped by Syafiq, Laziem, Faiz, Omar\n\n";
	cout<<"\t\t\tSupervised by Madam Suriani\n\n";
	cout<<"\n\n\n\t\t------------Nougat@CopyRight-------------\n\n";
	
}

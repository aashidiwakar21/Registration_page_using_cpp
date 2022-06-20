#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();
int main(){
	int c;
	cout<<"\t\t\t________________________________________________________________________\n\n\n";
	cout<<"\t\t\t______________________  welcome to the login page____________________\n\n\n";
	cout<<"\t\t\t_______________________        Menu          _____________________________\n\n\n";
	cout<<"                                                                                 \n\n";
	cout<<"\t| Press 1 to LOGIN                             |"<<endl;
	cout<<"\t| Press 2 to REGISTER                          |"<<endl;
	cout<<"\t| Press 3 if you forget your  PASSWORD         |"<<endl;
    cout<<"\t| Press 4 to EXIT                              |"<<endl;
    cout<<"\n\t\t\t  Please enter your choice  :";
    cin>>c;
    cout<<endl;
    
    
    switch(c)
    {
    	case 1:
    		login();
    		break;
    		
    		
    	case 2:
		registration();
		break;
		
		
		case 3:
		forgot();
		break;
		
		
		case 4:
		cout<<"\t\t\t  Thank you! \n\n";
		break;
		
		default:
			system("cls");//every time the code process it will clearup the screen 
		cout<<"\t\t\t Please select from the options given above \n"<<endl;
		main();	 //so that the control goes back to the main function ::
	}
}
void login(){
	int count;
	string userId,password,id,pass;
	system(" cls " );
	cout<<"\t\t\t Please entre the username  and password :"<<endl;
	cout<<"\t\t\t USERNAME ";
	cin>>userId;
	cout<<"\t\t\t PASSOWRD ";
	cin>>password;
	
	//now check if the username and password already exits or not 
	
	ifstream input("records.txt"); // ifstream is used to read the data from file  or to check data from file and input is the object name
	//now ifstream will check inside the password that the data exists or not;
	 while(input>>id>>pass){
	 	if(id==userId && pass==password){
	 		count=1;
	 		system("cls");
		 }
	 }
	input.close(); //close the file
	
	if(count==1){
		cout<<userId<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n";
		main();//shift the control to the main
		
	}
	else {
		cout<<"\n LOGIN ERROR \n Please check your username ans password \n ";	
		}
		
}
    void registration(){
    	string ruserId,rpassword,rid,rpass;
    	system("cls");
    	cout<<"\t\t\t Entre the username : ";
    	cin>>ruserId;
    	cout<<"\t\t\t Entre the passowrd :";
    	cin>>rpassword;
    	 //now using ofstream
    	ofstream f1("records.txt",ios::app); /*ofstream helps to write inside the file ans ios means
		 input output stream and app will open the file and append the output in the end */
		  //now write inside the file
		  f1<<ruserId<<" "<<rpassword<<endl;
		  system("cls");
		  cout<<"\t\t\t Registration is successfull! \n";
		  main();
	}
      void forgot(){
      	int option;
      	system("cls");
      	cout<<"\t\t\t You forget the password!  No worries \n";
      	cout<<"Press 1 to search your id by username "<<endl;
      	cout<<"Press 2 to go back to the main menu "<<endl;
      	cout<<"\t\t\t Entre your choice :" ;
      	cin>>option;
      	switch(option){
      		case 1:{ 
      		int count=0;
      		string suserId,sId,spass;
      		cout<<"\n\t\t\t Entre the username which you remembered :";
      		cin>>suserId;
      		  
      		  ifstream f2("records.txt");                  //ifstream class and f2 is  object name 
      		  while(f2>>sId>>spass){
      		  	if(sId==suserId){
      		  		count=1;
					}
				}
			f2.close();
			if(count ==1){
				cout<<"\n\n Your account is found! \n";
				cout<<"\n\n Your password is : "<<spass;
				main();
			}
			else {
				cout<<"\n\t Sorry! your account is not found! /n";
				main();
			}
			break;
			  }
			  case 2:
			  {
			  	main() ;//goback to the main menu 
			  }
			  default:
			  	cout<<"\t\t\t Wrong choice! Please try again "<<endl;
			  	forgot(); //so that the user can try again 
		  }
		  
		  	  }

 

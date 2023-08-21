
#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
//////////////////////////////////////
//////function prototypes/////////////
//////////////////////////////////////
void gotoxy(short , short );
void display();
void add();
void search();
void sort();
void del();
void modify();

struct student
    {
      char name[40];
      int rn;
      int age;
      char n[40];
      
    };
   
    struct student stud[50], stud1[50];
    int n=0;
//////////////////////////////////////
///////////////////main///////////////
/////////////////////////////////////
int main()
 {
 char ch1;
   while (1)
     {
        system("cls");
	   
	   cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl

          << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

 

          << setw( 25 ) << "( A ) add record" << endl << endl

          << setw( 31 ) << "( O ) sort all records" << endl << endl

          << setw( 34 ) << "( S ) search for a record" << endl << endl

          << setw( 31 ) << "( D ) display a record" << endl << endl

          << setw( 32 ) << "( T ) delete / undelete" << endl << endl

          << setw( 28 ) << "( M ) update record" << endl << endl
         
		  << setw( 19 ) << "( Q ) Quit" << endl << endl
		  <<setw( 30 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(28,21);
		//	cin>>ch1;
	     
	   
	  
      
	   switch(getche())
	  //switch(ch1)
       {
         case 'a':
		 case 'A':add();break;
         
		 case 'd':
		 case 'D': display();break;
         
		 case 'S':
		 case 's':search();break;
         
		 case 't':
		 case 'T':del();break;
		 
		 case 'O':
		 case 'o':sort();break;
         
		 case 'm':
		 case 'M':modify();break;
		 
		 case 'q':
		 case 'Q':exit(0);break;
         default:
		puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
		getch();
       } //end switch
     }//end while
    
	getch();
 }//end main

//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////

void display(void)
	{	
		system("cls");
		cout<< "in display function\n";
		cout<<setw(10)<<" Roll Number:"<<setw(20)<<"Name:"<<setw(20)<<"Age:"<<endl;
		cout<<setw(10)<<" -----------"<<setw(20)<<"------"<<setw(20)<<"-----"<<endl;
		for(int i=0;i<n;i++)
			{
				cout<<setw(6)<<stud[i].rn<<setw(25)<<stud[i].name<<setw(20)<<stud[i].age<<endl;
			}
			cout<<"Press enter to goto main manu.....";
			getch();
			
	}
	

//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(void)
	{
		char ch;char age1[6];
		char rn1[6];
		do
		{
			system("cls");
			cout<<endl;
			cout<< "in ADD function\n";
			cout<<"Enter Roll Number : ";
			gets(rn1);
			stud[n].rn=atoi(rn1);
			cout<<"enter name : ";    
			gets(stud[n].name);
			//cin.getline(stud[n].name,40);
			//cin.ignore(40,'\n');
			cout<<"eneter student age : ";
			gets(age1);
			stud[n].age=atoi(age1);
			//cin.ignore();
			n++;
		cout<<"do you want to add more recors [y/n]";
		ch=getch();
		}
		while(ch!='n'&& ch!='N');
	}

//////////Search////////////////////
void search(void)
	{
		int found, loc;
		int rn1;
		char ch;
		do
		{
		system("cls");
		cout<< "in SEARCH function\n\n";
		cout<<"Enter Roll Number : ";
		cin>>rn1;
		for(int j=0 ; j<=100 ; j++)
		{
			if (stud[j].rn == rn1)
			{
			    loc = j;
				found = 1;
			}
			   
        }
		 if (found == 1)
		 {
			cout<<"Record found\n";
			cout<<"Roll Number is : ";
			cout<<stud[loc].rn;
			cout<<"\nName is : ";
			cout<<stud[loc].name;
			cout<<"\nAge is = ";
			cout<<stud[loc].age;	
		  }
		  else
		  cout<<"\nNot Found";
		  
		  cout<<"\ndo you want to add more recors [y/n]";
	    	ch=getch();
	   }
		while(ch!='n'&& ch!='N');
		

}

//////////sort///////////////////////
void sort(void)
	{
		cout<< "in SORT function\n\n";
		system("cls");
		
			
		int r,a;
		string nam, nam2;
		int count = 0;
		for (int i=0; i<=100; i++ )
		{
			if (stud[i].rn>0)
			{
				count++;
			}
		}
		
		int counter = count-1;
	
	    
		
		for (int j=0 ; j<counter; j++)
		{
		
			
			
			
				if (stud[j].rn>stud[j+1].rn)
				{
					r = stud[j].rn;
					stud[j].rn = stud[j+1].rn;
					stud[j+1].rn = r;
					
					strcpy(stud1[j].n,stud[j].name);
					strcpy(stud[j].name,stud[j+1].name);
					strcpy(stud[j+1].name,stud1[j].n);
					
					a = stud[j].age;
					stud[j].age = stud[j+1].age;
					stud[j+1].age = a;
					
					
				}
		   
		}
		cout<<"***********Sheet in sorted form************\n";
		cout<<setw(10)<<" Roll Number:"<<setw(20)<<"Name:"<<setw(20)<<"Age:"<<endl;
		cout<<setw(10)<<" -----------"<<setw(20)<<"------"<<setw(20)<<"-----"<<endl;
		for(int k=0;k<count;k++)
			{
				cout<<setw(6)<<stud[k].rn<<setw(25)<<stud[k].name<<setw(20)<<stud[k].age<<endl;
			}
			cout<<"Press enter to goto main manu.....";
			getch();
		
		
	}

////////////Delete//////////////////////
void del(void)
	{
		cout<< "in DELETE function\n";
	}

///////////Modify//////////////////////
void modify(void)
	{
		cout<< "in MODIFY function\n";
	}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//////////////////////////////////////////

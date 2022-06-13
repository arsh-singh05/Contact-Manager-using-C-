/*
Project Title : Contact Manager
Developed By : Arshdeep Singh
*/


#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Searchmno(int);
class manager
{
  int Mno;
  char Name[20];
  char Mobile[20];
  char Landline[20];
  char Email[50];
  char Address[30];
  char City[30];
  char Country[30];
  char Postalcode[20];
  char Details[500];

public:
  void Modify();
  void Display();
  void Enter();
  int getMno()
  {return Mno;}
  char* getName()
  {return Name;}
  char* getMobile()
  {return Mobile;}
  char* getLandline()
  {return Landline; }
  char* getEmail()
  {return Email; }
  char* getAddress()
  {return Address; }
  char* getCity()
  {return City; }
  char* getCountry()
  {return Country; }
  char* getPostalcode()
  {return Postalcode;  }
  char* getDetails()
  {return Details; }
};

void manager::Enter()
{
  cout<<"Enter your member number:"<<endl;
  cin>>Mno;
  cout<<"Enter your name: "<<endl;
  gets(Name);
  cout<<"Enter mobile number: "<<endl;
  gets(Mobile);
  cout<<"Enter landline number: "<<endl;
  gets(Landline);
  cout<<"Enter your email: "<<endl;
  gets(Email);
  cout<<"Enter your address: "<<endl;
  gets(Address);
  cout<<"Enter your city: "<<endl;
  gets(City);
  cout<<"Enter your country: "<<endl;
  cin>>Country;
  cout<<"Enter your postal code: "<<endl;
  cin>>Postalcode;
  strcpy(Details,Name);
  strcat(Details,Mobile);
  strcat(Details,Landline);
  strcat(Details,Email);
  strcat(Details,Address);
  strcat(Details,City);
  strcat(Details,Country);
  strcat(Details,Postalcode);
}
void manager::Modify()
{
  cout<<"Re-enter details "<<endl;
  cout<<"Enter your name: "<<endl;
  gets(Name);
  cout<<"Enter mobile number: "<<endl;
  cin>>Mobile;
  cout<<"Enter landline number: "<<endl;
  cin>>Landline;
  cout<<"Enter your email: "<<endl;
  cin>>Email;
  cout<<"Enter your address: "<<endl;
  gets(Address);
  cout<<"Enter your city: "<<endl;
  gets(City);
  cout<<"Enter your country: "<<endl;
  gets(Country);
  cout<<"Enter your postal code: "<<endl;
  gets(Postalcode);
  strcpy(Details,Name);
  strcat(Details,Mobile);
  strcat(Details,Landline);
  strcat(Details,Email);
  strcat(Details,Address);
  strcat(Details,City);
  strcat(Details,Country);
  strcat(Details,Postalcode);
}
void manager::Display()
{
  cout<<"The member number is "<<Mno<<endl;
  cout<<"Name is "<<Name<<endl;
  cout<<"The mobile number is "<<Mobile<<endl;
  cout<<"The landline number is "<<Landline<<endl;
  cout<<"Email is "<<Email<<endl;
  cout<<"Address is "<<Address<<endl;
  cout<<"City is "<<City<<endl;
  cout<<"Postalcode is "<<Postalcode<<endl;
}
void create()
{
  fstream f1;
  manager m1;
  char ch;
  f1.open("MANAGER.DAT",ios::binary|ios::app);
  m1.Enter();
  if(Searchmno(m1.getMno())==0)
  {
    f1.write((char*)&m1,sizeof(m1));
    cout<<"Contact added!! ";
  }
  else
    cout<<"Mno is already present "<<endl;
  f1.close();
}
void Display()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT" ,  ios::in|ios::binary) ;
  while(f1.read((char *)&m1,sizeof(m1)))
  {
    m1.Display();
  }
  f1.close();
}
void Delete()
{
  char ch;
  int x;
  cout<<"Enter the mno to be deleted: ";
  cin>>x;
    fstream f1,f2;
    manager m1;
	f1.open("MANAGER.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",ios::binary|ios::out);
	int Enos,Del=0;
	while(f1.read((char *)&m1,sizeof(m1)))
	{
	  if(m1.getMno()!=x)
	    f2.write((char *)&m1,sizeof(m1));
	  else
	  {
	    m1.Display();
	    cout<<"\nAre you sure you want to delete this record? (Y/N)";
	    cin>>ch;
	    if(ch=='y'||ch=='Y')
	      cout<<"\n Successfully Deleted "<<endl;
	    else
	      f2.write((char *)&m1,sizeof(m1));
	   Del++;
	  }
	}
	if(Del==0)
	  cout<<x<<" This Mno does not exist! So no record deleted: "<<endl;
	f1.close();
	f2.close();
	remove("MANAGER.DAT");
	rename("TEMP.DAT","MANAGER.DAT");
}
void Edit()
{
  int x,c=0;
  cout<<"Enter the member no to be modified : ";
  cin>>x;
  Searchmno(x);
    fstream f1;
	manager m1;
	f1.open("MANAGER.DAT",ios::binary|ios::in|ios::out);
	while(f1.read((char*)&m1,sizeof(m1)))
	{
	  if(m1.getMno()==x)
	  {
	    cout<<"\n Details of "<<m1.getMno()<<"are as follows "<<endl;
		m1.Display();
		m1.Modify();
		f1.seekp(f1.tellp()-sizeof(m1));
		f1.write((char*)&m1,sizeof(m1));
		c=1;
	  }
	}
	if(c==0)
      cout<<"\n Sorry "<<x<<" does not Exist "<<endl;
  f1.close();
}
void Searchname()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  char name[200];
  int found=0;
  cout<<"Enter the name to be searched: ";
  cin>>name;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  if(strcmpi(name,m1.getName())==0)
  {
    m1.Display();
    found++;
  }
  if(!found)
    cout<<"Employee not found";
  f1.close();
}
int Searchmno(int x)
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  int found=0;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  {
   if(x==m1.getMno())
   {
     m1.Display();
     found++;
   }
  } 
  f1.close();
  return found;
}
void Searchmobile()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  char mobile[10];
  int found=0;
  cout<<"Enter the name to be searched: ";
  cin>>mobile;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  if(strcmp(mobile,m1.getMobile())==0)
  {
    m1.Display();
    found++;
  }
  if(!found)
    cout<<"NOT FOUND!!";
}
void Searchcity()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  char city[20];
  int found=0;
  cout<<"Enter the name to be searched: ";
  cin>>city;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  if(strcmp(city,m1.getCity())==0)
  {
    m1.Display();
    found++;
  }
  if(!found)
    cout<<"NOT FOUND!!";
}
void Searchcountry()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  char country[20];
  int found=0;
  cout<<"Enter the name to be searched: ";
  cin>>country;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  if(strcmp(country,m1.getCountry())==0)
  {
    m1.Display();
    found++;
  }
  if(!found)
    cout<<"NOT FOUND!!";
}
void Searchemail()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  char email[50];
  int found=0;
  cout<<"Enter the name to be searched: ";
  cin>>email;
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  if(strcmp(email,m1.getEmail())==0)
  {
    m1.Display();
    found++;
  }
  if(!found)
    cout<<"NOT FOUND!!";
}
void Powersearch()
{
  fstream f1;
  manager m1;
  f1.open("MANAGER.DAT",ios::binary|ios::in);
  manager E;
  char s[20];
  int found=0,j,k;
  cout<<"Enter the keyword to be searched: ";
  gets(s);
  while(!found && f1.read((char *)&m1,sizeof(m1)))
  {
    char t[2000];
    strcpy(t,m1.getDetails());
    int  f=0;
    for(int i=0;t[i]!='\0' && f==0;i++)
    {
      if(t[i]==s[0])
      {
         for(j=0,k=i;s[j]!='\0';j++,k++)
         {
	       if(s[j]!=t[k])
	       break;
         }
      if(s[j]=='\0')
	  f=1;
      }
    }
    if(f==1)
    {
      m1.Display();
 	  found=1;
    }
  }
  if(found==0)
    cout<<" Keyword does not Present";
  f1.close();
}
char* Changepassword(char z[])
{
  char p1[100],p2[100],p3[100];
  cout<<"\n Enter Old Password ";
  cin>>p1;
  if(strcmp(p1,z)==0)
  {
    cout<<"\n Enter New Password ";
	cin>>p2;
	cout<<"\n Confirm Password ";
	cin>>p3;
	  if(strcmp(p2,p3)==0)
	  strcpy(z,p2);
      else
      cout<<" \nPassword does not match "<<endl;
  }
  else
    cout<<"\n Password does not matched "<<endl;
	return z   ;
}
void main()
{
  clrscr();
  char x, y[100],ch,t, z[10]="bitsdxb",k[100];
  do
  {
    clrscr();
    cout<<"[A] Admin"<<endl;
	cout<<"[S] Search"<<endl;
    cout<<"[Q] Quit "<<endl;
	cin>>x;
    if(x=='a'||x=='A')
    {
	  clrscr();
	  cout<< " Enter Password "<<endl;
	  cin>>y;
	  if(strcmp(z,y)==0)
	  {
  	    do
	    {
	      clrscr();
	      cout<<"[A] Add Contact"<<endl;
	      cout<<"[R] Remove Contact"<<endl;
	      cout<<"[S] Show All Contact List"<<endl;
	      cout<<"[E] Edit Contact "<<endl  ;
	      cout<<"[C] Change Password "<<endl;
	      cout<<"[Q] Quit to Main Menu  "<<endl;
	      cin>>t;
	      switch(t)
	      {
	        case 'a':
	        case 'A':
		    create();
		    break;
	        case 'r':
	        case 'R':
		    Delete();
		    break;
	        case 's':
	        case 'S':
		    Display();
		    break;
	        case 'e':
	        case 'E':
		    Edit();
		    break;
	        case 'c':
	        case 'C':
		    strcpy(k,z);
		    strcpy(z,Changepassword(z));
		    if (strcmp(k,z)==0)
		      t='q';
		    else
		      cout<<" password changed successfully "<<endl;
		    break;
	        case 'q':
	        case 'Q':
		    break;
	        default:
		    cout<<"\n Invalid Option "<<endl;
	     }
	     getch();
	     while(t!='q'&& t!='Q');
        }
      }
      else if(x=='s'||x=='S')
      {
	    char ch;
	    clrscr();
	    do
	    {
	      cout<<"\n\n\n[A] Search by Name"<<endl;
	      cout<<"[B] Search by Mno"<<endl;
	      cout<<"[C] Search by Mobile"<<endl;
	      cout<<"[D] Search by City"<<endl;
	      cout<<"[E] Search by Country"<<endl;
	      cout<<"[F] Search by Email"<<endl;
	      cout<<"[P] Power Search"<<endl;
	      cout<<"[Q] Quit"<<endl;
	      cin>>ch;
	      if(ch=='a'||ch=='A')
	        Searchname();
	      else if(ch=='b'||ch=='B')
	      {
	        int x;
	        cout<<"Enter the mno to be searched : ";
	        cin>>x;
	        Searchmno(x);
	      }
	      else if(ch=='c'||ch=='C')
	        Searchmobile();
	      else if(ch=='d'||ch=='D')
	        Searchcity();
	      else if(ch=='e'||ch=='E')
	        Searchcountry();
	      else if(ch=='f'||ch=='F')
	        Searchemail();
	      else if(ch=='p'||ch=='P')
	        Powersearch();
	    }while(!(ch=='q'|| ch=='Q'));
	  }
	}
    cout<<"\n \n Press any key to continue...";
    getch();
    }while(!(x=='q' || x=='Q'));
  getch();
}

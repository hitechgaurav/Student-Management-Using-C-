#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<limits>
#include<stdio.h>
#include<ctype.h>
using namespace std;
class student
{
	private:
		char name[30];
		char age[2];
		char address[150];	
		char str[60];
		char pursue[60];
		char dob[10];
	int is_valid(char d[])
	{
	int check=0;
	int tmp;
	int k=10;
	char slash='/';
	if(d[2]==slash&&d[5]==slash)
	{
		for(int i=0;i<2;i++)
		{
			if(!isdigit(d[i]))
			{
				return 0;
			}
			else
			continue;
		}
		for(int i=0;i<2;i++)
		{
			tmp=d[i];
			tmp-='0';
			check+=(tmp*k);
			k/=10;
		}
		if(check>31)
		{
			return 0;
		}
		else
		{
			check=0;
			k=10;
			for(int i=3;i<5;i++)
			{
				if(!isdigit(d[i]))
				{
					return 0;
				}
			}
			for(int i=3;i<5;i++)
			{
				tmp=d[i];
				tmp-='0';
				check+=(tmp*k);
				k/=10;
			}
			if(check>12)
			{
				return 0;
			}
			else
			{
				check=0;
				k=1000;
				for(int i=6;i<10;i++)
				{
					if(!isdigit(d[i]))
					{
						return 0;
					}
				}
				for(int i=6;i<10;i++)
				{
					tmp=d[i];
					tmp-='0';
					check+=(tmp*k);
					k/=10;
				}
				if(check<1900||check>2018)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
	else
	return 0;
}
void get_age()
{
	int arr[4];
	int tmp;
	int k=1000;
	int get=0;
	for(int i=0;i<5;i++)
	{
		arr[i]=dob[i+6];
		arr[i]-='0';
	}
	for(int i=0;i<5;i++)
	{
		tmp=arr[i];
		get+=(tmp*k);
		k/=10;
	}
	int show=2018;
	show-=get;
	cout<<show;
}
	public:
		char roll[13];
		void input()
			{
				int i,j,k;
				k:
				cout<<"\nEnter name:- ";
				gets(name);
					for(i=0;name[i]!='\0';i++)
					{
						if(isdigit(name[i])||name[i]=='!'||name[i]=='@'||name[i]=='#'||name[i]=='$'||name[i]=='%'||name[i]=='^'||name[i]=='&')
						{
							cout<<"\n***SORRY! INVALID INPUT PLEASE ENTER THE NAME AGAIN***"<<endl;
							goto k;
						}
					}
				int t;
				t:
				cout<<"\nEnter ROLL NUMBER:- ";
				cin.get(roll,13);
				{
					if(isalpha(roll[4])&&isalpha(roll[5]))
					{
						for(int i=0;i<4;i++)
						{
							if(!isdigit(roll[i]))
							{
								cout<<"\n***INVALID INPUT,PLEASE ENTER ROLL AGAIN***"<<endl;
								cin.ignore();
								goto t;
							}
							else
							continue;
						}
						for(int j=6;j<12;j++)
						{
							if(!isdigit(roll[j]))
							{
								cout<<"\n***INVALID INPUT,PLEASE ENTER ROLL AGAIN***"<<endl;
								cin.ignore();
								goto t;
							}
							else
							continue;
						}
					}
						else
						{
							cout<<"\n***INVALID INPUT,PLEASE ENTER ROLL AGAIN***"<<endl;
							cin.ignore();
							goto t;
						}
				}	
				int u;
				u:
				cin.ignore();
				cout<<"\nEnter stream:- ";
				gets(str);
				for(int i=0;str[i]!='\0';i++)
				{
					if(isdigit(str[i]))
					{
						cout<<"\nINVALID INPUT PLEASE ENTER STREAM AGAIN.";
						goto u;
					}
					else
					continue;	
				}
				strcpy(pursue,str);
				//cout<<"strcpy"<<roll<<endl;	
				cout<<"\nEnter Address:- ";
				gets(address);	
				//cout<<"add"<<roll<<endl;			
			
	}
			void output()
			{
				cout<<"\n--------------------------------------------------------"<<endl;
				cout<<"\nName :- ";
				cout<<name;
				cout<<"\nRoll Number:- "<<roll;
				cout<<"\nPursuing:- "<<pursue;
				cout<<"\nDate of Birth:- "<<dob;
				cout<<"\nAge:- ";
				get_age();
				cout<<"\nAddress:- "<<address;
				cout<<"\n--------------------------------------------------------"<<endl;
			}
			char *retroll()
			{
				return &roll[0];
			}
};
int is_empty()
{
	int length;
	ifstream fin;
	fin.open("student.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	length=fin.tellg();
	fin.close();
	return length;
}
void write_data()
{
	int v;
	student ob;
	student obj;
	fstream fin;
	fin.open("student.dat",ios::binary|ios::in);
	ofstream fout;
	fout.open("student.dat",ios::binary|ios::app);
	v:
	ob.input();
	while(fin.read((char *)&obj,sizeof(obj)))
	{
		if(strcmp(obj.retroll(),ob.roll)==0)
		{
			cout<<"\n***Roll Number already exist.***"<<endl;
			cout<<"\n---WRITING FAILED---"<<endl;
			cout<<"\n```PLEASE ENTER ALL DATA AGAIN```"<<endl;
			goto v;
		}
	}
	fout.write((char*)&ob,sizeof(ob));
	fout.close();
}
void read_data()
{
	int checkend;
	ifstream fin;
	student ob;
	fin.open("student.dat",ios::binary|ios::in);
	checkend=is_empty();
		if(checkend==0)
		{
			char ch[3];
			cout<<"\n***SORRY! DATABASE IS BLANK***"<<endl;
			cout<<"\n##Do you want to write some data to database##:- ";
				cin>>ch;
				cin.ignore();
				if(strcmp(ch,"yes")==0||strcmp(ch,"Yes")==0||strcmp(ch,"YES")==0)
				{
					write_data();
				}
				else
				exit(0);
		}
		else
	while(fin.read((char*)&ob,sizeof(ob)))
	{
		ob.output();
		cout<<endl;
	}
}
void data_delete(char x[10])
{
	student ob;
	int flag=0;
	ifstream fin1;
	fin1.open("student.dat",ios::binary|ios::in);
	while(fin1.read((char *)&ob,sizeof(ob)))
	{
		if(strcmp(ob.retroll(),x)==0)
		{
			cout<<"\n***Data Found***"<<endl;
			cout<<"\n***DATA DELETED FROM DATABASE***"<<endl;
			flag=1;
			break;
		}
	}
	fin1.close();
	if(flag==1)
	{
			student obj;
			student obj1;
			ifstream fin;
			fin.open("student.dat",ios::in);
			if(!fin)
			{
				cout<<"\nFILE NOT OPENED";
				return;
			}
			ofstream fout;
			fout.open("temp.dat",ios::binary|ios::out);
			if(!fout)
			{
				cout<<"\nFILE NOT OPENED";
				return;
			}
			while(fin.read((char *)&obj,sizeof(obj)))	
			{	
				if(strcmp(obj.retroll(),x)!=0)
				{
					fout.write((char *)&obj,sizeof(obj));
				}
			}
			fin.close();
			fout.close();
			remove("student.dat");
			rename("temp.dat","student.dat");
			ifstream in;	
			in.open("student.dat",ios::binary|ios::in);
			if(!in)
			{
				cout<<"\n***FILE NOT OPENED***";
				return;
			}
			int checkend;
			char ch[3];
			cout<<"\nCurrent database is:- "<<endl;\
			checkend=is_empty();
			if(checkend==0)
			{
				cout<<"\n***BLANK***"<<endl;
				cout<<"\n##Do you want to write some data to database##:- ";
				cin>>ch;
				cin.ignore();
				if(strcmp(ch,"yes")==0||strcmp(ch,"Yes")==0||strcmp(ch,"YES")==0)
				{
					write_data();
				}
				else
				exit(0);
			}
			else
			while(in.read((char *)&obj1,sizeof(obj1)))
			{
				obj1.output();
				cout<<endl;
			}
			in.close();
	}
	if(flag==0)
	{
		int checkend;
		char ch[3];
		checkend=is_empty();
		if(checkend==0)
		{
			cout<<"\nFile is empty now."<<endl;
			cout<<"\n##Do you want to write some data to database##:- ";
			cin>>ch;
			cin.ignore();
				if(strcmp(ch,"yes")==0||strcmp(ch,"Yes")==0||strcmp(ch,"YES")==0)
				{
					write_data();
				}
				else
				exit(0);
		}
		else
		cout<<"\n***Data not found***"<<endl;
		return;
	}
}
void search_data(char x[10])
{
	int flag=0;
	int checkend;
	checkend=is_empty();
		if(checkend==0)
		{
			char ch[3];
			cout<<"\n***SORRY! DATABASE IS BLANK***"<<endl;
			cout<<"\n##Do you want to write some data to database##:- ";
				cin>>ch;
				cin.ignore();
				if(strcmp(ch,"yes")==0||strcmp(ch,"Yes")==0||strcmp(ch,"YES")==0)
				{
					write_data();
				}
				else
				exit(0);
		}
		else
		{
			student obj;
			ifstream fin;
			fin.open("student.dat",ios::binary|ios::in);	
			while(fin.read((char*)&obj,sizeof(obj)))
			{
				if(strcmp(obj.retroll(),x)==0)
				{
					flag=1;
					cout<<"\nDATA FOUND AS FOLLOWING:- "<<endl;
					obj.output();
				}
			}
			if(flag==0)
			cout<<"\nSORRY!!DATA NOT FOUND"<<endl;
		}
}
void edit_data(char m[10])
{
	student ob;
	fstream fin;
	int flag=0;
	fin.open("student.dat",ios::binary|ios::in|ios::out);
	while(fin.read((char *)&ob,sizeof(ob)))
	{
		if(strcmp(ob.retroll(),m)==0)
		{
			flag=1;
			cout<<"\nDATA FOUND AS FOLLOWING:- "<<endl;
			ob.output();
			fin.seekg(-sizeof(ob),ios::cur);
			ob.input();
			fin.seekp(fin.tellg(),ios::cur);
			fin.write((char *)&ob,sizeof(ob));
		}
	}
	if(flag==0)
	{
		cout<<"\nOOPS!!,SORRY NO DATA FOUND"<<endl;
	}	
	fin.close();
}
int main()
{	
	int a1,a2,i;
	char in[3],ch;
	char spass[5],spass2[5];//password for student is"GUEST"and official is"SYSTM"
	cout<<"\t\t`````````````````````````````````````````````````````````````````````"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t::::WELCOME TO STUDENT MANAGEMENT SYSTEM::::"<<endl;
	cout<<endl;
	cout<<"\t\t`````````````````````````````````````````````````````````````````````"<<endl;
	a2:
	cout<<"\n||PLEASE PROVIDE LOGIN CREDENTIALS||"<<endl;
	cout<<"\n!!ARE YOU A STUDENT OR AN OFFICIAL??"<<endl;
	cin>>in;
	if(strcmp(in,"Student")==0||strcmp(in,"student")==0||strcmp(in,"STUDENT")==0)
	{
		a1:
		i=0;
		cout<<"\nEnter Student password:- "<<endl;
		ch=_getch();
		while(i!=5)
		{
			cout<<"*";
			spass[i]=ch;
			ch=_getch();
			i++;
		}
		if(strcmp(spass,"GUEST")==0)
		{
			int m1,l1,c1;
			char s[3];
			cout<<"\n---LOGGED IN SUCCESSFULLY.---"<<endl;
			m1:
			cout<<"\n\t\t\t\t\t::MENU::"<<endl;
			cout<<"*********************************";
			cout<<"\nPRESS 1 TO ENTER STUDENT DATA";
			cout<<"\nPRESS 2 TO SEARCH STUDENT DATA";
			cout<<"\nPRESS 3 TO LOG OUT PROFILE";
			cout<<"\nPRESS 4 TO EXIT CONSOLE"<<endl;
			cout<<"*********************************"<<endl;
			cin>>c1;
			cin.ignore();
			switch(c1)
			{
				case 1:
				{
					l1:
					write_data();
					cout<<"\n***Data written to FILE.***"<<endl;
					cout<<"\nDo you want to enter more data:- ";
					cin>>s;
					cin.ignore();	
					if(strcmp(s,"yes")==0||strcmp(s,"Yes")==0||strcmp(s,"YES")==0)
					goto l1;
					else 
					goto m1;
					break;
				}
				case 2:
					{
							char r1[12];
							int i;
							char q[3];
							i:
							cout<<"\nEnter Student's Roll whose data you want to search:- ";
							gets(r1);
							search_data(r1);
							cout<<"\nDo you want to search more data:- ";
							cin>>q;
							cin.ignore();
							if(strcmp(q,"yes")==0||strcmp(q,"Yes")==0||strcmp(q,"YES")==0)
							goto i;
							else
							goto m1;
							break;			
					}
					case 3:
						{
							cout<<"\n---LOGGED OUT SUCCESSFULLY.---"<<endl;
							goto a2;
						}
				case 4:
					exit(0);
				default:
					{
						cin.clear();
						cin.ignore();
						cout<<"\nINVALID INPUT.";
						goto m1;
					}
		}
	}
		else
		{
			
			cout<<"\n***Login Failed.***"<<endl;
			cout<<"\n***Invalid password,PLEASE ENTER AGAIN.***"<<endl;
			goto a1;
		}
	}
	else
	if(strcmp(in,"Official")==0||strcmp(in,"official")==0||strcmp(in,"OFFICIAL")==0)
	{
		int a3,j;
		char ch2;
		a3:
			i=0;
		cout<<"\nEnter OFFICIAL password:- "<<endl;
		ch2=_getch();
		while(i!=5)
		{
			cout<<"*";
			spass2[i]=ch2;
			ch2=_getch();
			i++;
		}
		if(strcmp(spass2,"SYSTM")==0)
		{
			cout<<endl<<"\n---LOGGED IN SUCCESSFULLY.---"<<endl;
			int l,m;
			int c;
			char s[3];
			m:
			cout<<"\n\t\t\t\t\t::MENU::"<<endl;
			cout<<"*********************************";	
			cout<<"\nPRESS 1 TO ENTER STUDENT DATA";
			cout<<"\nPRESS 2 TO VIEW STUDENT DATA";
			cout<<"\nPRESS 3 TO DELETE STUDENT DATA";
			cout<<"\nPRESS 4 TO SEARCH STUDENT DATA";
			cout<<"\nPRESS 5 TO EDIT STUDENT DATA";
			cout<<"\nPRESS 6 TO LOG OUT PROFILE";
			cout<<"\nPRESS 7 TO EXIT CONSOLE"<<endl;
			cout<<"*********************************"<<endl;
			cin>>c;
			cin.ignore();
			switch(c)
			{
				case 1:
				{
					l:
					write_data();
					cout<<"\n***Data written to FILE.***"<<endl;
					cout<<"\nDo you want to enter more data:- ";
					cin>>s;
					cin.ignore();	
					if(strcmp(s,"yes")==0||strcmp(s,"Yes")==0||strcmp(s,"YES")==0)
					goto l;
					else 
					goto m;
					break;
				}
				case 2:
				{
						read_data();
						goto m;
						break;
				}
				case 3:
				{
						int r;
						char t[12];
						int z;
						char d[3];
						r:
						cout<<"\nEnter the roll number whose data you want to delete:- ";
						gets(t);
						data_delete(t);
						cout<<"\nDo you want to delete more data:- ";
						cin>>d;
						if(strcmp(d,"yes")==0||strcmp(d,"Yes")==0||strcmp(d,"YES")==0)
						goto r;
						else
						goto m;	
						break;
				}	
					case 4:
					{
							char r1[12];
							int i1;
							char q[3];
							i1:
							cout<<"\nEnter Student's Roll whose data you want to search:- ";
							gets(r1);
							search_data(r1);
							cout<<"\nDo you want to search more data:- ";
							cin>>q;
							cin.ignore();
							if(strcmp(q,"yes")==0||strcmp(q,"Yes")==0||strcmp(q,"YES")==0||strcmp(q,"y")==0)
							goto i1;
							else
							goto m;
							break;			
					}
					case 5:
					{
							char y[12];
							int p;
							char q[3];
							p:
							cout<<"\nEnter Roll number whose data to be Edited:- ";
							gets(y);
							cin.ignore();
							edit_data(y);
							cout<<"\nDo you want to edit more data:- ";
							cin>>q;
							if(strcmp(q,"yes")==0||strcmp(q,"Yes")==0||strcmp(q,"YES")==0)
							goto p;
							else
							goto m;
							break;
							
					}
						case 6:
							{
								cout<<"\n---LOGGED OUT SUCCESSFULLY.---"<<endl;
								goto a2;
							}
						case 7:
							exit(0);
						default:
							{
								cin.clear();
								cin.ignore();
								cout<<"\nINVALID INPUT";
								goto m;	
							}
						
				};	
			}
			else
			{
				cout<<"\n***Invalid password,PLEASE ENTER AGAIN.***"<<endl;
				goto a3;
			}
		}		
	else
	{
		cout<<"\n***Login Failed.***"<<endl;
		cout<<"\n***SORRY! INVALID INPUT PLEASE ENTER AGAIN.***"<<endl;
		goto a2;
	}
	return 0;	
}

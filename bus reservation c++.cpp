#include<iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;
char ch[10][130]={"Cardiff Express","Belfast Express","Derby Express","Chester Express","Newport Express","Truro Express"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();
void login();//added by me
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int trno);//for reading the number from the file
void read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void cancle();



int main()
{
	login();
    int num,i;
    do{
    system("cls");
    cout<<"\n\n\n";
    cout<<"====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n";
    cout<<"\t\t\t\t\t[1]=> View Bus List\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t[2]=> Book Tickets\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t[3]=> Cancle Booking\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t[4]=> Bus Status Board\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t[5]=> Exit\n\n";
	cout<<"===============================================================================================================\n\n";
    cout<<"\t\t\tEnter Your Choice:: ";
    cin>>num;
    switch(num)
    {
    case 1:
        bus();//for list of bus
        break;
    case 2:
        booking();//for booking the tickets
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    cout<<"\t----------------------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n";
    cout<<"\t----------------------------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t Brought To You By GROUP I";
    getch();
    return 0;
}




void bus()
{
    system("cls");
    cout<<"\n\n\n";
    cout<<"=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";
    cout<<"\t\t\t\t\t[1]  =>  "<<ch[0]<<"\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t[2]  =>  "<<ch[1]<<"\n";
    cout<<"\n"; 
	cout<<"\t\t\t\t\t[3]  =>  "<<ch[2]<<"\n";
    cout<<"\n"; 
	cout<<"\t\t\t\t\t[4]  =>  "<<ch[3]<<"\n";
    cout<<"\n"; 
	cout<<"\t\t\t\t\t[5]  =>  "<<ch[4]<<"\n";
}

void booking()
{

    int i=0;
    char numstr[100];
system("cls");
cout<<"=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";//for entering train number
bus();//for seeing train least
cout<<"Enter the Bus number:--->";
cin>>trno;
system("cls");
cout<<"=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";//for selecting coach
cout<<"Your Bus Number is "<<trno<<" ********** %s"<<ch[trno-1];
status_1(trno);
 FILE *f1;//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 cout<<"There is no blank seat in this bus ";
}else
{
cout<<"\n\n\n\t\t\t\tAvailable Seats:------>"<<seat1<<"\n";
cout<<"\n\t\t\t\tNumber of Tickets:----->";
cin>>booking;
cout<<"\n";

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
cout<<"\n\t\t\t\tThe Total booking amount is "<<200*booking;
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
cout<<"============================Enter the details for ticket no "<<i+1<<"============================\n\n\n";
      cout<<"\t\t\t\tEnter the seat number:--->";
      cin>>number;
      cout<<"\t\t\t\tEnter the name of person:--->";
      cin>>name[number-1];
    cout<<"\n======================================================================================================\n\n";
    cout<<"\n";
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
cout<<"=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";
    int i,trno,index=0,j;
    cout<<"Enter the number of bus:---->";
    cin>>trno;
    j=read_number(trno);
    read_name(trno);
    cout<<"____________________________________________________________________________________________________________________\n";
    cout<<"                                      Bus.no-->"<<trno<<"---->"<<ch[trno-1]<<"                                                            \n";
    cout<<"____________________________________________________________________________________________________________________\n";
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        cout<<"\t\t\t\t";
        for(j=0; j<4; j++)
            {
        cout<<index+1<<"."<<tempname[index+1];
        index++;
            }
            cout<<"\n";
    }
}

void status_1(int trno)
{
    cout<<"Your Bus Number is" <<trno<<" ********** "<<ch[trno-1];
    system("cls");
cout<<"=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n";
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        cout<<"\t\t\t\t";
        for(j=0; j<4; j++)
            {
        cout<<index+1<<"."<<tempname[index+1];
        index++;
            }
            cout<<"\n";
}
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 cout<<"Enter the bus number:---->";
 cin>>trno;
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 cout<<"Enter the seat number:--->";
 cin>>seat_no;
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
cout<<"\n\n";
    cout<<"======================================================================================================\n";
 cout<<"\t\t\t\tYour 200 rupees has been Returned\t\t\t\n";
    cout<<"======================================================================================================\n";
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	cout<<"\n************************PEARL SEATS***********************\n\n\n";
    cout<<"\n  =========================  LOGIN FORM  =========================  ";
    cout<<" \n                       ENTER USERNAME:-";
	cin>>uname; 
	cout<<" \n                       ENTER PASSWORD:-";
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else cout<<"*";
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	cout<<"  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL";
	cout<<"\n\n\n\t\t\t\tPress any key to continue...";
	getch();//holds the screen
	break;
	}
	else
	{
		cout<<"\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		cout<<"\n Sorry you have entered the wrong username and password for four times!!!";
		
		getch();
		
	}
		system("cls");	
}

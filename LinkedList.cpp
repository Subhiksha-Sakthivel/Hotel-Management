#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace std::chrono;
struct Book
{
  int  ID;
  int s,d;
};
struct Customer
{
  char Name[20];
  int age;
  char email[50];
  long int phone;
  double amount;
  Book B;
  Customer *next;
};
class Hotel_Management
{
  static int b_id;
  Customer *head;
  public:
  	static int sr,dr;
    Hotel_Management()
    {
      head=NULL;
    }
    void insert();
    void display();
    void deleten(int key);
    int search(int key);
};
int Hotel_Management::b_id=1234;
int Hotel_Management::dr=140;
int Hotel_Management::sr=120;
void Hotel_Management::insert()
{
  Customer *node=new Customer;
  int temp;
  if(head==NULL)
  {
    head=node;
  }
  else
  {
    Customer *curr;
    curr=head;
    while(curr->next!=NULL)
      curr=curr->next;
    curr->next=node;
  }  
  node->next=NULL;
  cout<<"Select room type: 1]Single Room        2]Double Room       3]Both \nEnter your choice: ";
  cin>>temp;
  if (temp==1)
    {
      int c;
      cout<<"Number of available rooms:"<<sr<<"\n";
      cout<<"Enter number of rooms to be booked:";
      cin>>c;
      if(sr-c>0)
      {
        node->B.s=c;
        sr=sr-c;
        cout<<"Enter Name:";
        cin>>node->Name;
        cout<<"Enter age:";
        cin>>node->age;
        cout<<"Enter your email id: ";
        cin>>node->email;
        cout<<"Enter your phone number: ";
        cin>>node->phone;
        node->B.ID=b_id;
        b_id++;
        cout<<"Booking Successfull!!!\n";
        cout<<" "<<"Your Booking Id is:"<<" "<<node->B.ID;
      }
      else
      {
          cout<<"Entered number of rooms cannot be booked................";
      }
    }
      
  if(temp==2)
    {
      int c;
      cout<<"Number of available rooms:"<<" "<<dr<<"\n";
      cout<<"Enter number of rooms to be booked: ";
      cin>>c;
      
      if(dr-c>0)
      {
       
        dr=dr-c;
        node->B.d=c;
        cout<<"Enter Name:";
        cin>>node->Name;
        cout<<"Enter age:";
        cin>>node->age;
        cout<<"Enter your email id: ";
        cin>>node->email;
        cout<<"Enter your phone number: ";
        cin>>node->phone;
        node->B.ID=b_id;
        b_id++;
        cout<<"Booking Successfull!!!\n";
        cout<<" "<<"Your Booking Id is:"<<" "<<node->B.ID;  
      }
      else 
        {
        cout<<"Entered number of rooms cannot be booked................";
        }
    }
    
    if(temp==3)
    {
        int c,d;
        cout<<"Number of available Single rooms:"<<sr<<"\n";
        cout<<"Enter number of single rooms to be booked:";
        cin>>c;
        if(sr-c>0)
      {
        cout<<"Enter Name:";
        cin>>node->Name;
        cout<<"Enter age:";
        cin>>node->age;
        cout<<"Enter your email id: ";
        cin>>node->email;
        cout<<"Enter your phone number: ";
        cin>>node->phone;
        node->B.ID=b_id;
        b_id++;
          node->B.s=c;
          sr=sr-c;
          cout<<"Booking Successfull!!!\n";
      }
      else
      {
          cout<<"Entered number of rooms cannot be booked................";
      }
        
        cout<<"Number of available Double rooms:"<<" "<<dr<<"\n";
        cout<<"Enter number of double rooms to be booked: ";
        cin>>d;
         
      if(dr-d>0)
      {
        node->B.d=d;
        dr=dr-d;
        cout<<"Booking Successfull!!!\n";
        cout<<" "<<"Your Booking Id is:"<<" "<<node->B.ID;  
      }
      else 
        {
        cout<<"Entered number of rooms cannot be booked................";
        }
        
    }
}
void Hotel_Management::deleten(int bid)
{
    Customer *temp = head;
    if (temp->B.ID == bid){
      sr=sr+temp->B.s;
      dr=dr+temp->B.d;
      head = temp->next;
      cout<<"Cancellation Successful";
      return;
       }
    while(temp != NULL)
    {
        if(temp->next != NULL)
        {
        if (temp->next->B.ID == bid)
        {
        cout<<"\t Room Cancelled";
        sr=sr+temp->B.s;
        dr=dr+temp->B.d;
        temp->next = temp->next->next; 
       return;
        }
        }
      temp=temp->next;
    }
    
}

int Hotel_Management::search(int bid)
{

    Customer *temp = head;
    while(temp != NULL)
    {
         if(temp->B.ID== bid)
            {
            	cout<<"\nReservation Status: Booked\n";
                cout<<"Name:"<<temp->Name<<endl;
                cout<<"Booking Id:"<<temp->B.ID<<endl;
                if(temp->B.s>0){
                cout<<"Number of single rooms booked:"<<temp->B.s<<endl;}
                if(temp->B.d>0){
                cout<<"Number of double rooms booked:"<<temp->B.d<<endl;}
                return 1;

            }
         temp = temp->next;
    }
    return -1;
}

 void Hotel_Management::display()
 {
   Customer *curr;
   curr=head;
   while(curr!=NULL)
     {
        cout<<curr->Name<<endl;
        cout<<curr->age<<endl;
        cout<<curr->B.ID<<endl;
        curr=curr->next;
     }
 }
int main()
{
  Hotel_Management H;
  time_t start_time, end_time;
  double time_taken;
  int a=324,temp,res;
  cout<<"\n\t\t\t*****HOTEL ICHIRAKU*****";
  cout<<"\n\t\t---Welcome to Hotel Ichiraku---";
  cout<<"\n\t\tHope you enjoy your stay!!";
  while(a!=0)
  {
    cout<<"\n\nSelect Operation: \n\t1]Book room\n\t2]Check Reservation\n\t3]Cancel Booking\n\t0]Exit";
    cout<<"\nEnter your choice: ";
    cin>>a;
  switch(a)
  {
    case 1:
       H.insert();
       break;
        
    case 2:
    {
      int temp;
      cout<<"Enter your booking id: ";
      cin>>temp;
      auto start = high_resolution_clock::now();
      res=H.search(temp);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
    	cout << "\nTime taken by program for searching is : " << duration.count();
    	cout << " microseconds " << endl;
      if (res==1)
        break;
      else
        cout<<"Reservation Status: Not Booked\n";
        break;    
  }   
   case 3:
        int test;
        cout<<"Enter your booking id: ";
        cin>>test;
        H.deleten(test);
        break;
        
    case 19:
        H.display();
 }
}
}

#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class Hotel
{
 char roomn[6] = {"Empty"}, host[10] = {"Empty"}, start[6] = {"Empty"}, send[6] = {"Empty"}, from[10] =
{"Empty"}, to[10] = {"Empty"}, chair[8][4][10];
public:
 void Registration();
 void allotment();
 void empty();
 void show();
 void available();
 void position(int i);
}
room[32];
void vline(char ch)
{
 for (int i = 80; i > 0; i--)
 cout << ch;
}
void Hotel::Registration()
{
 cout << "Enter Room no: ";
 cin >> room[p].roomn;
 cout << "\nEnter Host's name: ";
 cin >> room[p].host;
 cout << "\nStart time: ";
 cin >> room[p].start;
 cout << "\nSession Ends at: ";
 cin >> room[p].send;
 cout << "\nFrom: \t\t\t";
 cin >> room[p].from;
 cout << "\nTo: \t\t\t";
 cin >> room[p].to;
 room[p].empty();
 p++;
}
void Hotel::allotment()
{
 int chair;
 char number[5];
top:
 cout << "Room no: ";
 cin >> number;
 int n;
 for (n = 0; n <= p; n++)
 {
 if (strcmp(room[n].roomn, number) == 0)
 break;
 }
 while (n <= p)
 {
 cout << "\nChair Number: ";
 cin >> chair;
 if (chair > 32)
 {
 cout << "\nThere are only 32 Chair available in this Room.";
 }
 else
 {
 if (strcmp(room[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0)
 {
 cout << "Enter traveller's name: ";
 cin >> room[n].chair[chair / 4][(chair % 4) - 1];
 break;
 }
 else
 cout << "The Chair no. is already reserved.\n";
 }
 }
 if (n > p)
 {
 cout << "Enter correct Room no.\n";
 goto top;
 }
}
void Hotel::empty()
{
 for (int i = 0; i < 8; i++)
 {
 for (int j = 0; j < 4; j++)
 {
 strcpy(room[p].chair[i][j], "Empty");
 }
 }
}
void Hotel::show()
{
 int n;
 char number[5];
 cout << "\nEnter Room no: ";
 cin >> number;
 cout << "\n";
 for (n = 0; n <= p; n++)
 {
 if (strcmp(room[n].roomn, number) == 0)
 break;
 }
 while (n <= p)
 {
 vline('*');
 cout << "\nRoom no: " << room[n].roomn
 << "\nHost : " << room[n].host << "\t\tStart time: "
 << room[n].start << "\t\tEnd time: " << room[n].send
 << "\nFrom : " << room[n].from << "\t\tTo : " <<
 room[n].to << "\n\n";
 vline('*');
 room[0].position(n);
 int a = 1;
 for (int i = 0; i < 8; i++)
 {
 for (int j = 0; j < 4; j++)
 {
 a++;
 if (strcmp(room[n].chair[i][j], "Empty") != 0)
 cout << "\nThe Chair no " << (a - 1) << " is reserved for " << room[n].chair[i][j] << ".";
 }
 }
 break;
 }
 if (n > p)
 cout << "Enter correct Room no: ";
}
void Hotel::position(int l)
{
 int s = 0;
 p = 0;
 for (int i = 0; i < 8; i++)
 {
 cout << "\n";
 for (int j = 0; j < 4; j++)
 {
 s++;
 if (strcmp(room[l].chair[i][j], "Empty") == 0)
 {
 cout.width(5);
 cout.fill(' ');
 cout << s << ".";
 cout.width(10);
 cout.fill(' ');
 cout << room[l].chair[i][j];
 p++;
 }
 else
 {
 cout.width(5);
 cout.fill(' ');
 cout << s << ".";
 cout.width(10);
 cout.fill(' ');
 cout << room[l].chair[i][j];
 }
 }
 }
 cout << "\n\nThere are " << p << " Chairs empty in Room No: " << room[l].roomn;
}
void Hotel::available()
{
 for (int n = 0; n <= p; n++)
 {
 cout << n + 1 << ".\n";
 vline('_');
 cout << "\n\nRoom no: " << room[n].roomn << "\nHost : " << room[n].host
 << "\t\tStart time: " << room[n].start << "\t\tEnd time: "
 << room[n].send << "\nFrom : " << room[n].from << "\t\tTo : "
 << room[n].to << "\n";
 vline('_');
 cout << "\n\n\n\n";
 }
}
int main()
{
 system("cls");
 int w;
 cout << "\n___________________GRAND WELCOME IN OUR VIRTUAL HOTEL___________________
\n\n ";
 while (1)
 {
 cout << "\n\n\n\n\n";
 cout << "\t\t\t1.Registration\n\t\t\t"
 << "2.Reservation\n\t\t\t"
 << "3.Show\n\t\t\t"
 << "4.Rooms Available. \n\t\t\t"
 << "5.Exit";
 cout << "\n\t\t\tEnter your choice:-> ";
 cin >> w;
 switch (w)
 {
 case 1:
 room[p].Registration();
 break;
 case 2:
 room[p].allotment();
 break;
 case 3:
 room[0].show();
 break;
 case 4:
 room[0].available();
 break;
 case 5:
 cout << " \n\n we hope,\n all enjoy our service and wish you all the best for your next journey. \n
Thank you \n\n\n\n";
 exit(0);
 }
 }
 return 0;
}

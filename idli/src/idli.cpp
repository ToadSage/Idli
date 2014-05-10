#include <iostream>
#include <idli.h>

using namespace std;

int main(int argc, const char** argv ) {
	database data;
	itemInfo item ;
	unsigned int choice, rfout,temp_weight;
	string s;
	cout<<"Enter \n1 to add new item\n2 to remove item\n3 to return the item\n4 to display contents recorded\n0 to exit"<<endl;


	do
	{
		//_(INVARIANT loop iff choice!=0)
		//_(INVARIANT myMap is unmodified)
		cin>>choice;
		switch(choice)
		{
		case 0:
			cout << "program terminated" << endl;
			return 0;
		case 1:
			cout<<"Enter details:"<<endl;
			item.getbarcode();
			item.getrfid();
			item.getweight();
			data.add(item);
			break;
		case 2:
			cout<<"which Grocery do u want to take out"<<endl;
			cin>>rfout;
			data.find(rfout);
			break;

		case 3:
			cout<<"which Grocery do u want to put in"<<endl;
			cin>>rfout;
			cout<<"what is the weight now"<<endl;
			cin>>temp_weight;
			data.update(rfout,temp_weight);
			break;
		case 4:
				map<string, itemInfo> :: iterator it;
			for (it=data.myMap.begin(); it!=data.myMap.end(); ++it)
			{
				//_(INVARIANT <=it
				it->second.display();
			}
			break;

		default:
			cout<<"Invalid choice !"<< endl;
			cout<<"Enter \n1 to add new item\n2 to remove item\n3 to return the item\n4 to display contents recorded\n0 to exit"<<endl;
		}
	}while(choice);
}

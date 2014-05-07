#include <databaseImplement.h>

using namespace std;

void database:: add(itemInfo grocery)
{
	ofstream myFile;
	map<string, itemInfo> :: iterator it;
	static int i=0;
	char choice;
    
    for (it=myMap.begin(); it!=myMap.end(); ++it)
    {
        if(it->second.rfid==grocery.rfid)
        {
            cout<<"This RFID already exists in your database. Do u want to remove " << it->second.getname() <<" from the list." << endl << "(Y OR N)";
            cin>>choice;
            
            switch(choice)
            {
				case 'Y':
					it->second.Timerupdate();
					myMap.erase(it);
					break;
				case 'N':
					cout<<"Try with another RFID tag.";
					cin >> grocery.rfid;
					add(grocery);
					break;
            }
        }
    }
    
    
	myMap[grocery.rfid]=grocery;
    myFile.open("theList.txt", ios::trunc);
	for (it=myMap.begin(); it!=myMap.end(); ++it)
    {
		myFile<<it->second.name<<"  "<<it->second.weight<<"  "<<it->second.status<<"  "	<<it->second.rfid<<endl;
    }
	myFile.close();
	cout << "Data successfully added!" <<endl;
}

void database :: find(string rfid)
{
	map<string, itemInfo> :: iterator it;
	for (it=myMap.begin(); it!=myMap.end(); ++it)
	{
		if(it->second.rfid==rfid)
			it->second.statusupdate();
	}
}


void database :: update(string rfid, float weight)
{
	map<string, itemInfo> :: iterator it;
	for (it=myMap.begin(); it!=myMap.end(); ++it)
    {
        if(it->second.rfid==rfid)
            it->second.weightupdate(weight);
    }
    
}



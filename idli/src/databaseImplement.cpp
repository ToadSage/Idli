#include <databaseImplement.h>

using namespace std;
// don't bake io into your classes
void database:: add(itemInfo grocery)
{
	ofstream myFile;
	map<string, itemInfo> :: iterator it;
	static int i=0;
	char choice;
    
    for (it=myMap.begin(); it!=myMap.end(); ++it)
    {
		// traverses through the map, if there is a conflict, depending on the users choice deletion  of conflicting id or insertion of new id will be done
        if(it->second.rfid==grocery.rfid)
        {
            cout<<"This RFID already exists in your database. Do you want to remove " << it->second.getname() <<" from the list." << endl << "(Y OR N)";
            cin>>choice;
            
            switch(choice)
            {
				// whenever there is a conflict (same rfid is being logged in ) depending on users 
				//choice the old one will be removed and mapped to the new object
				//or a new rfid is obtained to map
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

// a functiopn called find usually would be const
// the name should indicate the effect of the update
void database :: find(string rfid)
{
	// move deckaration into the loop
	// good place to use auto instead of the explicit type
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



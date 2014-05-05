
#include <databaseImplement.h>
using std::cout;
using std::cin;
using std::endl;

void database:: add(itemInfo stuff)
{
	static int i=0;
	char c;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==stuff.rfid)
				cout<<"RFID Exists do u want to rem-ove "<<it->second.getname()<<"from the list (Y OR N)";
				cin>>c;
		
				switch(c)
				{
				case 'Y':
					it->second.Timerupdate();
					mymap.erase(it);
					break;
				case 'N':
					cout<<"try another rfid";
					cin>>stuff.rfid;
					add(stuff);
					break;
				}
		}
	//mymap.insert ( std::pair<int,itemInfo> (i,stuff) );
		mymap[i]=stuff;
	i++;
	cout << "data successfully added!" <<endl;
}

void database :: find(int rfid)
{
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	{
		if(it->second.rfid==rfid)
			it->second.statusupdate();
	}
}


void database :: update(int rfid, float weight)
{
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==rfid)
				it->second.weightupdate(weight);
		}

}



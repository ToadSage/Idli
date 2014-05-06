
#include <databaseImplement.h>
using std::cout;
using std::cin;
using std::endl;

void database:: add(itemInfo stuff)
{
	fstream myfile;
	map<string, itemInfo> :: iterator it;
	static int i=0;
	char c;
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==stuff.rfid)
			{
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
		}
	//mymap.insert ( std::pair<int,itemInfo> (i,stuff) );
	mymap[stuff.rfid]=stuff;
	      	fout.open("filename.txt", ios::app)
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
		fout<<it->second.name<<"  "<<it->second.weight<<"  "<<it->second.status<<"  "	<<it->second.rfid<<endl;
		}
	fout.close();
	cout << "data successfully added!" <<endl;
}

void database :: find(string rfid)
{
	map<string, itemInfo> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	{
		if(it->second.rfid==rfid)
			it->second.statusupdate();
	}
}


void database :: update(string rfid, float weight)
{
	map<string, itemInfo> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==rfid)
				it->second.weightupdate(weight);
		}

}



/*
 * Database.h
 *
 *  Created on: May 4, 2014
 *      Author: Srinivasan
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <itemInfo.h>
#include <map>
using  std::map;
class database
{
public:
	map <int, itemInfo> mymap;
	map <int, itemInfo> :: iterator it;
	 void add(itemInfo);
	 void find(int);
	 void update(int , float );
};



#endif /* DATABASE_H_ */

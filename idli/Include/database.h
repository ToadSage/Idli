#ifndef DATABASE_H_
#define DATABASE_H_
#include <itemInfo.h>
#include <map>
using  std::map;
class database
{
public:
    /* data structure to store the details of the item */
    map <string, itemInfo> myMap;
    void add(itemInfo);
    void find(int);
    void update(int,float);
};



#endif /* DATABASE_H_ */

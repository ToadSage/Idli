#ifndef DATABASE_H_
#define DATABASE_H_
#include <itemInfo.h>
#include <map>
using  std::map;

// why isn't this just a map? the methods seem to just be ordinary map methods
class database
{
public:
    /* Data structure to store the details of the item. */
    map <string, itemInfo> myMap;
    void add(itemInfo);
    void find(int);
    void update(int,float);
};



#endif /* DATABASE_H_ */

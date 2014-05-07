#ifndef DATABASE_H_
#define DATABASE_H_
#include <itemInfo.h>
#include <map>
using  std::map;
class database
{
public:
    
    map <string, itemInfo> myMap;
    void add(itemInfo);
    void find(int);
    void update(int,float);
};



#endif /* DATABASE_H_ */
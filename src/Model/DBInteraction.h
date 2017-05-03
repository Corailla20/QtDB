
#ifndef SINGLETON_H
#define SINGLETON_H

class DBInteractor
{
public:
    static DBInteractor& Instance();
private:
    DBInteractor& operator= (const DBInteractor&){}
    DBInteractor (const DBInteractor&){}

    static DBInteractor db_instance;
    DBInteractor();
    ~DBInteractor();
};
#endif

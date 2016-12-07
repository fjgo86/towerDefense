
#include "../logger/log.h"

#include "db.h"

DB::DB() {  

    try {
        _driver = get_driver_instance();
        //_con = _driver->connect("tcp://127.0.0.1:3306", "root", "root");
        _con = _driver->connect("tcp://35.156.52.33:3306", "root", "root");
        _con->setSchema("server");
    } catch (sql::SQLException &e){
        _ERRORLOG("MySQL Error: " << e.getErrorCode())
    }
}

DB::~DB() {
    delete _con;
}

sql::Connection* DB::getConnection() {
    return _con;
}

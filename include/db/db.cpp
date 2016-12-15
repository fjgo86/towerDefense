
#include <logger/logger.h>
#include <networking/config.h>
#include "db.h"
#include <string>

DB::DB() {  
    try {
        _driver = get_driver_instance();
        std::stringstream ip;
        ip << MYSQL_IP << ":" << MYSQL_PORT;
        _con = _driver->connect(ip.str() ,
            MYSQL_USER,
            MYSQL_PW);
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

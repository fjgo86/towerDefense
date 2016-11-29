#pragma once
#pragma warning (disable : 4100)    //warning.h(64): warning C4100: 'e': unreferenced formal parameter
#include <mysql_connection.h>
#pragma warning (default : 4100)

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/*
* brief Clase que se encarga de todo lo relacionado con la Base de Datos.
*/
extern class DB {
private:
    sql::Driver *_driver;
    sql::Connection *_con;
public:
    DB();
    ~DB();

    /*
    * @brief Devuelve la Connection de la BD.
    */
    sql::Connection* getConnection();
} gMySQL;
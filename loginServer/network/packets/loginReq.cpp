#include "loginReq.h"
#include <string>

#include <logger/logger.h>
#include <db/db.h>
#include <networking/packets.h>
#include "../../accounts/account.h"
#include "../clients/client.h"
#include "loginResp.h"

#define TABLECUENTAS "cuentas"
#define ROWUSER "user"
#define ROWPW "pw"

class Account;
PacketLoginReq::PacketLoginReq() {
}


PacketLoginReq::~PacketLoginReq() {
}

void PacketLoginReq::doReceive(Client *theClient, sf::Packet theData) {

    std::string nombre;
    std::string password;
    Account *cuenta = NULL;
    AccConnectMsg status = ACM_QTY;

    if (theData >> nombre >> password) {
        status = checkAccount(nombre, password, cuenta);
    }
    else {
        _ERRORLOG("PacketLogin: Error recibiendo datos.\n");
        status = ACM_MISC;
    }
    if (status == ACM_Ok) {
        theClient->setAccount(cuenta);
    }
    else {
        _LOG(Log::LogLevel::LOGLVL_EVENT, "Error en el Login: " << (int)status << "\n");
    }
    reply(theClient, status);
}

PacketLoginReq::AccConnectMsg PacketLoginReq::checkAccount(std::string user, std::string pw, Account *theAccount) {
    std::stringstream sqlQuery;
    _LOG(Log::LOGLVL_EVENT, "Comprobando usuario '" << user << "', contraseña '" << pw << "'\n");
    // Query para la búsqueda de la cuenta y retorno de todos sus datos.
    sqlQuery << "SELECT * from " << TABLECUENTAS 
        << " WHERE " << ROWUSER << " = '" << user 
        << "' AND " << ROWPW << " = '" << pw << "'";
    sql::Statement *stmt;
    sql::ResultSet *res;
    try {
        stmt = gMySQL.getConnection()->createStatement();
        res = stmt->executeQuery(sqlQuery.str());
        if (!res->first())  // Usuario & contraseña no encontrados/coinciden.
            return ACM_UserPw;
        theAccount = new Account(res->getInt(0),    // Una vez existen datos válidos se procede a la creación de la Account.
                             res->getString(1).c_str());
        return ACM_Ok;
    }
    catch (sql::SQLException &e) {
        _ERRORLOG("MySQL Error: " << e.getErrorCode() << "\n'" << e.what() << "'\n");
        return ACM_BD;
    }
    return ACM_QTY;
}

void PacketLoginReq::reply(Client *theClient, PacketLoginReq::AccConnectMsg loginStatus) {

    sf::Packet retPacket;
    retPacket << PacketID::LoginResp << loginStatus;
    theClient->send(retPacket);
}
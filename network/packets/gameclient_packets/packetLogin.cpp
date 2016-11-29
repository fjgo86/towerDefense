#include "packetLogin.h"
#include <string>

#include "../../logger/log.h"
#include "../../accounts/account.h"
#include "../clients/client.h"
#include "../db.h"
#include "listado_paquetes.h"

#define TABLECUENTAS "cuentas"
#define ROWUSER "user"
#define ROWPW "pw"

class Account;
PacketLogin::PacketLogin(Client *client, sf::Packet data) {
	std::string nombre;
	std::string password;
    Account *cuenta = NULL;
    PacketLogin::AccConnectMsg ret = ACM_QTY;

    if (!readPacket(data, nombre, password)) {
        ret = ACM_MISC;
    }
    else {
        ret = checkAccount(nombre, password, cuenta);
    }
    if (ret == ACM_Ok) {
        client->setAccount(cuenta);
    }
    else {
        _LOG(Log::LogLevel::LOGLVL_EVENT, "Error en el Login: "<< (int)ret << "\n");
    }
    sf::Packet retPacket;
    retPacket << PacketID::PACKET_Login << ret;
    client->send(retPacket);
}


PacketLogin::~PacketLogin() {
}

bool PacketLogin::readPacket(sf::Packet data, std::string &user, std::string &pw) {
    if (data >> user >> pw) {
        _LOG(Log::LOGLVL_EVENT, "Comprobando usuario '" << user << "', contraseña '" << pw << "'\n");
        return true;
    }
    else {
        _ERRORLOG("PacketLogin: Error recibiendo datos.\n");
        return false;
    }
}

PacketLogin::AccConnectMsg PacketLogin::checkAccount(std::string user, std::string pw, Account *cuenta) {
    std::stringstream sqlQuery;

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
        cuenta = new Account(res->getInt(0),    // Una vez existen datos válidos se procede a la creación de la Account.
                             res->getString(1).c_str());
        return ACM_Ok;
    }
    catch (sql::SQLException &e) {
        _ERRORLOG("MySQL Error: " << e.getErrorCode() << "\n'" << e.what() << "'\n");
        return ACM_BD;
    }
    return ACM_QTY;
}
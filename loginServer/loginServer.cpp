#include "loginServer.h"
#include <GitRevision.h>
#include <logger/log_manager.h>
#include <logger/logger.h>
#include <db/db.h>

LogManager gLog;
DB gMySQL;

LoginServer::LoginServer() {
	isActive = true;
}

LoginServer::~LoginServer() {
	delete _network;
}

bool LoginServer::onTick() {
	gLog.onTick();
	_network->onTick();
	return true;
}

void LoginServer::init() {
    _LOG(Log::LOGLVL_EVENT, "Iniciado servidor en la version '" << __GITREVISION__ << "'.\n");
	_network = new ServerListener();
    while (isActive) {
        isActive = onTick();
    }
}
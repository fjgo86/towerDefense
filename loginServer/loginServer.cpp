#include "loginServer.h"
#include <logger/log_manager.h>
#include <logger/logger.h>
#include <GitRevision.h>


LogManager gLog;
DB gMySQL;

LoginServer::LoginServer() {
	isActive = true;
}

LoginServer::~LoginServer() {
	delete _network;
}

bool LoginServer::onTick() {
	//if (isActive) {
		gLog.onTick();
		_network->onTick();
		return true;
	//}
	return false;
}

void LoginServer::init() {
    _LOG(Log::LOGLVL_EVENT, "Iniciado servidor en la version '" << __GITREVISION__ << "'.\n");
	_network = new ServerListener();
}
#include "LoginServer.h"

Logger gLog;
DB gMySQL;

LoginServer::LoginServer() {
	isActive = true;
}

LoginServer::~LoginServer() {
	delete _network;
}

bool LoginServer::onTick() {
	if (isActive) {
		gLog.onTick();
		_network->onTick();
		return true;
	}
	return false;
}

void LoginServer::init() {
	_network = new Network();
}
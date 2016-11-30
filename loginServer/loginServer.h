#pragma once 

#include "../logger/log.h"
#include "../logger/logger.h"

#include "network/serverListener.h"
#include "../db/db.h"


extern class LoginServer {
private:
    bool isActive;
public:
    ServerListener* _network;

    LoginServer();
    ~LoginServer();

    bool onTick();
    void init();
} gServer;
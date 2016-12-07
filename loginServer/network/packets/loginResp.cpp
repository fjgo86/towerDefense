#include "loginResp.h"
#include <string>

#include <networking/packets.h>


PacketLoginResp::PacketLoginResp(Client* client, AccConnectMsg status) : PacketOut(LoginResp) {
    (*this) << status;
    client->send(*this);
    delete this;
}

PacketLoginResp::~PacketLoginResp() {
}

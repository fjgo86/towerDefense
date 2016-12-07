#include "loginReq.h"
#include <logger/logger.h>
#include <networking/packets.h>

PacketLoginReq::PacketLoginReq(std::string user, std::string pw) : PacketOut(LoginReq) {
    (*this) << user << pw;
}

PacketLoginReq::~PacketLoginReq() {
}

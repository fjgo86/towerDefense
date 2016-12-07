#include "account.h"
#include <db/db.h>

Account::Account(int id, const char* nombre) {
    _nombre = nombre;
    _id = id;
}


Account::~Account() {
}
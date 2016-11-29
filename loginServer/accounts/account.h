#pragma once

class Account {
private:
    const char* _nombre;
    int _id;
public:
	Account(int id, const char* nombre);
	~Account();
};


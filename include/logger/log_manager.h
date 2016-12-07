#pragma once
#include <string>
#include <vector>
#include <logger/log.h>

extern class LogManager : public std::vector<Log*> {

private:

public:
    LogManager() {}
    ~LogManager() {
        clearData();
    }

    /*
    Añade un Log al vector de la clase.
    */
    void addLog(Log* log) {
        push_back(log);
    }
    /*
    Ejecuta un tick del Logger (Envía los Log existentes a la consola).
    */
    void onTick() {
        for (unsigned int i = 0; i < size(); i++) {
            Log* log = (*this)[i];
            if (log) {
                log->printText();
                delete log;
            }
        }
        clear();
    }
    /*
    Borra todos los datos que hay dentro
    */
    void clearData() {
        for (unsigned int i = 0; i < size(); i++) {
            delete (*this)[i];
        }
        clear();
    }
} gLog;
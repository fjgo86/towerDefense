#include "log.h"
#include <iostream>
#include <stdlib.h>
#include "logger.h"


Logger::Logger() {
}

Logger::~Logger() {
	clearData();
}

void Logger::addLog(Log* log) {
	push_back(log);
}

void Logger::onTick() {
	for (unsigned int i = 0; i < size(); i++) {
        Log* log = (*this)[i];
        if (log) {
            log->printText();
			delete log;
        }
	}
	clear();
}

void Logger::clearData() {
	for (unsigned int i = 0; i < size(); i++) {
		delete (*this)[i];
	}
	clear();
}


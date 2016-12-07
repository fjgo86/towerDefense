#include <logger\log.h>
#include <logger\log_manager.h>

/*
Crea un Log Detallado:
x = LogLevel
f = __FILE__
l = __LINE__
m = __func__
txt = Texto a mostrar
*/
#define _LOGDETAILED(x, f, l, m, txt) { \
	std::stringstream s; \
	s << txt; \
    gLog.addLog(new Log(x, f, l, m, s.str().c_str())); \
 }

/*
Crea un Log Simple:
x = LogLevel
txt = Texto a mostrar
*/
#define _LOG(x, txt) { \
	std::stringstream s; \
	s << txt; \
    gLog.addLog(new Log(x, s.str().c_str())); \
 }

/*
Crea un _LOGDETAILED del tipo LOGLVL_DEBUG
*/
#define _DEBUGLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_DEBUG, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_EVENT
*/
#define _EVENTLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_EVENT, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_WARNING
*/
#define _WARNINGLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_WARNING, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_ERROR
*/
#define _ERRORLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_ERROR, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_CRITICAL
*/
#define _CRITICALLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_CRITICAL, __FILE__, __LINE__, __func__, txt); \
}


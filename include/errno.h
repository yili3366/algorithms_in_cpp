#ifndef __ERRNUMBER_H__
#define __ERRNUMBER_H__

#include "apue.h"

const int ERRFALSE = 1;
const int TRUE = 0;

#define _err_msg(_format, _args...) \
        err_msg("file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_dump(_format, _args...) \
        err_dump("file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_quit(_format, _args...) \
        err_quit("file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_cont(error, _format, _args...) \
        err_cont(error, "file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_exit(error, _format, _args...) \
        err_exit(error, "file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_ret(_format, _args...) \
        err_ret("file:%s, line:%d " _format "\n", __FILE__, __LINE__);

#define _err_sys(_format, _args...) \
        err_sys("file:%s, line:%d " _format "\n", __FILE__, __LINE__);
#endif

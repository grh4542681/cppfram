#ifndef __PROCESS_RETURN_H__
#define __PROCESS_RETURN_H__

namespace process {

/**
 * @brief process module return value.
 */
enum class ProcessRet: int {
//common return val
    SUCCESS = 0,
    ERROR = -999,
    EMALLOC,
    EINIT,
    ETIMEOUT,
    EBADARGS,
    EUNKOWNERRNO,

// process info
    PROCESS_EACCES,
    PROCESS_EFAULT,
    PROCESS_EINVAL,
    PROCESS_EIO,
    PROCESS_ELOOP,
    PROCESS_ENAMETOOLONG,
    PROCESS_ENOENT,
    PROCESS_ENOMEM,
    PROCESS_ENOTDIR,
};

}

#endif
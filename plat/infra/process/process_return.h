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

//process common
    PROCESS_EMEMORY,

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
    PROCESS_ETHREADDUP,
    PROCESS_ETHREADADD,
    PROCESS_ETHREADNOTFOUND,
    PROCESS_EPROCDUP,
    PROCESS_EPROCADD,
    PROCESS_EPROCNOTFOUND,

//process signal
    PROCESS_ESIGINVAL,

//process single
    PROCESS_ECALLABLE,
    PROCESS_EFORK,
    PROCESS_EFIFOPAIR,
};

}

#endif

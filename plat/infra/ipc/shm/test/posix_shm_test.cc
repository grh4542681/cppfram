#include <unistd.h>
#include "string.h"
#include "shm/shm_posix.h"
#include "shm/shm_mode.h"

int main()
{
    ipc::shm::ShmPosix shm("posix_shm_text");
    if (shm.Create(0666, 1024) != ipc::IpcRet::SUCCESS) {
        printf("-----------\n");
        return 0;
    }
    sleep(10);
    shm.Open(ipc::shm::ShmMode::READ_WRITE);
    void* p = shm.GetHeadPtr();
    printf("%p\n", p);
//    memcpy((char*)p, "hello", 5);
    shm.Sync();
    sleep(10);
    shm.Close();
    sleep(10);
    shm.Destroy();
    return 0;
}
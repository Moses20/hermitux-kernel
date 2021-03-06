#include <hermit/syscall.h>
#include <hermit/logging.h>
#include <lwip/sockets.h>

extern int hermit_getpeername(int s, struct sockaddr *name, socklen_t *namelen);

int sys_getpeername(int s, struct sockaddr *name, socklen_t *namelen) {
#ifndef NO_NET
	return hermit_getpeername(s, name, namelen);
#else
	LOG_ERROR("Network disabled, cannot process socket syscall!\n");
	return -ENOSYS;
#endif /* NO_NET */

}

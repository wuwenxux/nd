#include <stdlib.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>

#include "uapi/if_nd.h"
/*typedef struct nd_req
{
    u32 cmd;
    u32 num_peers;
    u32 status;
    u32 flags;   
    bool server;
    char peer_ip[14];
    char endpoint_ip[14];
}ndreq_t */

int main( int argc ,char *argv[])
{
    int sockfd, len;
    struct ifreq ifr;
    struct ndreq_t ndreq;

    if ( ( sockfd = socket( AF_INET, SOCK_DGRAM, 0 ) ) < 0 )
    printf( "can't create socket" );
    if(argc > 2)
    {
        
            
    }
    
    return 0;
}

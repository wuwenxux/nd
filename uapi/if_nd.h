#ifndef _UAPI_LINUX_IF_ND_H_
#define _UAPI_LINUX_IF_ND_H_
#include <linux/types.h>
#include "peer.h"
#define USER_IOC_CMD  (SIOCDEVPRIVATE)
/*
*   User defined cmds
*/
#define ND_START 0x001
#define ND_STOP 0X002
#define PEERS_COUNT 0x003
#define CLI_SERVER 0x004
#define G_PEER_IP 0x005
#define S_PEER_IP 0x006

typedef struct nd_req
{
    u32 cmd;
    u32 num_peers;
    u32 status;
    u32 flags;   
    bool server;
    char peer_ip[14];
    char endpoint_ip[14];
}ndreq_t

void nd_start(ifreq_t *ifr_ptr);
void nd_stop(ifreq_t *ifr_ptr);
void print_hello(ifreq_t *ifr_ptr);
void send_req(ifreq_t *if_ptr);
void usage();

#endif
#ifndef _ND_PEER_H_
#define _ND_PEER_H_

#include <sys/socket.h>
#include "device.h"
struct  peer
{   
    struct net_device *dev;
    u16 peer_port;
    struct addr_in peer_ip;
    struct endpoint endpoint;
    struct sk_buff_head pascket_queue;
    struct list_head peer_node; 
    bool isdead;
}
struct endpoint
{
    union
    {
        struct sockaddr addr;
        struct sockaddr_in addr4;
    };
    struct 
    {
        struct in_addr src4;
        int src_if4;
    }
};

struct peer *nd_peer_create(struct nd_device *ndev);
void peer_put(struct peer *peer);
void peer_remove(struct peer *peer);
void peer_remove_all(struct nd_device *all);

#endif
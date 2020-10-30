#ifndef _ND_DEVICE_H_
#define _ND_DEVICE_H_

#include <linux/netdevice.h>
#include <linux/types.h>
#include "peer.h"

struct nd_device;
struct nd_device{
    struct list_head peer_list;
    struct net_device *netdevice;
    u16 incoming_port;
    u32  numb_peers;
    struct mutex device_update_lock;
    u32 bytes_queued;
}

int __init nd_device_init(void)
{
    int ret;
}
void nd_device_unit(void);
#endif
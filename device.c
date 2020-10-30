#include "peer.h"
#include "timer.h"
#include "device.h"

#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <net/ip_tunnels.h>
#include <net/addrconf.h>
#include <linux/mutex.h>
static int nd_open(struct net_device *dev);
static int nd_close(struct net_device *dev);
static int nd_ioctl(struct net_device *dev,struct *ifreq,int cmd);
static netdev_tx_t nd_xmit(struct sk_buff *skb,struct net_device *dev);
static const struct net_device_ops nd_netdev_ops = {
	.ndo_open	= nd_open,
	.ndo_stop	= nd_close,
	.ndo_do_ioctl	= nd_ioctl,
	.ndo_start_xmit	= nd_xmit,
};
static void nd_setup(struct net_device *dev)
{
    struct nd_device *nd = netdev_priv(dev);
    mutex_init(nd->device_update_lock);
    INIT_LIST_HEAD(nd->peer_list);

    dev->netdev_ops = &nd_netdev_ops;

}
static int nd_open(struct net_device *dev)
{
    
    return 0;
}
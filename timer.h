#ifndef _ND_TIMERS_H_
#define _nd_TIMERS_H_
#include <linux/timer.h>
#include "device.h"
struct nd_eql
{
    struct timer_list timer;


}
struct nd_peer;
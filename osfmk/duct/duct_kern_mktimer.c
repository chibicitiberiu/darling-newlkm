/*
Copyright (c) 2014-2017, Wenqi Chen

Shanghai Mifu Infotech Co., Ltd
B112-113, IF Industrial Park, 508 Chunking Road, Shanghai 201103, China


All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


*/

#include "duct.h"
#include "duct_pre_xnu.h"
#include "duct_kern_mktimer.h"

#if defined (XNU_USE_MACHTRAP_WRAPPERS_MKTIMER)
mach_port_name_t xnusys_mk_timer_create_trap (struct mk_timer_create_trap_args * args)
{
        return mk_timer_create_trap (args);
}

kern_return_t xnusys_mk_timer_destroy_trap (struct mk_timer_destroy_trap_args * args)
{
        printk (KERN_NOTICE "- args->name: 0x%x \n", args->name);

        return mk_timer_destroy_trap (args);
}

kern_return_t xnusys_mk_timer_arm_trap (struct mk_timer_arm_trap_args * args)
{
        printk (KERN_NOTICE "- args->name: 0x%x, expire_time: 0x%x \n", args->name, (unsigned int) args->expire_time);

        return mk_timer_arm_trap (args);
}

kern_return_t xnusys_mk_timer_cancel_trap (struct mk_timer_cancel_trap_args * args)
{
        printk (KERN_NOTICE "- args->name: 0x%x, result_time: 0x%x \n", args->name, args->result_time);

        return mk_timer_cancel_trap (args);
}
#endif

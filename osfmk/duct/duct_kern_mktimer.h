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
#ifndef DUCT_KERN_MKTIMER_H
#define DUCT_KERN_MKTIMER_H

#include <mach/mach_types.h>
#include <mach/mach_traps.h>

#define XNU_USE_MACHTRAP_WRAPPERS_MKTIMER

#if defined (XNU_USE_MACHTRAP_WRAPPERS_MKTIMER)
extern mach_port_name_t xnusys_mk_timer_create_trap (struct mk_timer_create_trap_args * args);
extern kern_return_t xnusys_mk_timer_destroy_trap (struct mk_timer_destroy_trap_args * args);
extern kern_return_t xnusys_mk_timer_arm_trap (struct mk_timer_arm_trap_args * args);
extern kern_return_t xnusys_mk_timer_cancel_trap (struct mk_timer_cancel_trap_args * args);
#else
#define xnusys_mk_timer_create_trap                 mk_timer_create_trap
#define xnusys_mk_timer_destroy_trap                mk_timer_destroy_trap
#define xnusys_mk_timer_arm_trap                    mk_timer_arm_trap
#define xnusys_mk_timer_cancel_trap                 mk_timer_cancel_trap
#endif
#endif // DUCT_KERN_MKTIMER_H

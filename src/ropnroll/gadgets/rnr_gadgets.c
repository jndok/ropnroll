//
//  rnr_gadgets.c
//  ropnroll_final
//
//  Created by jndok on 27/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#include "rnr_gadgets.h"

__attribute__((always_inline)) uint32_t rnr_calculate_gadget_size(gadget_t gadget)
{
    char *byte = (char*)gadget;
    uint32_t sz;

    for (sz=0; *(uint8_t*)(byte+sz) != 0xc3; ++sz);

    return sz+1;
}

__attribute__((always_inline)) void rnr_dump_gadget(gadget_t gadget, gadget_size_t gadget_size)
{
    uint32_t ret=0;
    csh handle;

    ret=cs_open(CS_ARCH_X86, CS_MODE_64, &handle);
    if (ret!=CS_ERR_OK)
        return;

    cs_insn *insn;
    uint64_t count = cs_disasm(handle, (uint8_t*)gadget, gadget_size, 0x0, 0, &insn);
    for (uint32_t i=0; i<count; ++i) {
        printf("%s %s\n", insn[i].mnemonic, insn[i].op_str);
    }

}

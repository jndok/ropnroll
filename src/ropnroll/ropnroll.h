//
//  ropnroll.h
//  ropnroll_final
//
//  Created by jndok on 14/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#ifndef ropnroll_h
#define ropnroll_h

#define KSLIDE_UNKNOWN -1

#define KAS_INFO_KERNEL_TEXT_SLIDE_SELECTOR (0)
#define KAS_INFO_MAX_SELECTOR (1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <capstone/capstone.h>

#include "types.h"
#include "macho/rnr_macho.h"

extern uint64_t KextUnslidBaseAddress(const char *KextBundleName);

gadget_map_t *map_file_with_path(const char *path);

uint32_t calculate_gadget_size(gadget_t gadget);
void dump_gadget(gadget_t gadget, gadget_size_t gadget_size);

uint64_t locate_gadget_in_map(gadget_map_t *map, gadget_t gadget, gadget_size_t sz);
uint64_t *locate_gadget_group_in_map(gadget_map_t *map, gadget_t gadget, gadget_size_t sz, uint32_t occurrences);
uint64_t locate_symbol_in_map(gadget_map_t *map, const char *sym_name);

uint64_t locate_kernel_base(gadget_map_t *map);

uint64_t kext_base_address(const char *bundle_id);

uint64_t get_kslide(void);
__attribute__((always_inline)) uint64_t slide_kernel_pointer(uint64_t pointer, uint64_t kslide);

#endif /* ropnroll_h */

//
//  rnr_macho.c
//  ropnroll_final
//
//  Created by jndok on 26/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#include "rnr_macho.h"

__attribute__((always_inline)) struct mach_header_64 *find_mach_header_in_map(gadget_map_t *map)
{
    struct mach_header_64 *header = (struct mach_header_64*)map->map;
    if (header->magic != MH_MAGIC_64)
        return NULL;
    
    return header;
}

__attribute__((always_inline)) struct load_command *find_load_command_in_map(gadget_map_t *map, uint32_t cmd)
{
    struct mach_header_64 *header = find_mach_header_in_map(map);
    
    struct load_command *lcmd = ((void*)header + sizeof(struct mach_header_64));
    for (uint32_t i=0; i<header->ncmds; ++i) {
        if (lcmd->cmd==cmd) {
            return lcmd;
        }
        
        lcmd = ((void*)lcmd + lcmd->cmdsize);
    }
    
    return NULL;
}

__attribute__((always_inline)) struct segment_command_64 *find_segment_in_map(gadget_map_t *map, const char *segname)
{
    return (struct segment_command_64*)find_load_command_in_map(map, LC_SEGMENT_64);
}

__attribute__((always_inline)) struct section_64 *find_section_in_segment_in_map(struct segment_command_64 *seg, const char *sectname)
{
    if (!seg)
        return NULL;
    
    struct section_64 *sec=(struct section_64*)((void*)seg+sizeof(struct segment_command_64));
    for (uint32_t i=0; i<seg->nsects; ++i) {
        if (strcmp(sec->sectname, sectname) == 0) {
            return sec;
        }
        
        sec = ((void*)sec + sizeof(struct section_64));
    }
    
    return NULL;
}

__attribute__((always_inline)) struct symtab_command *find_symbol_table_in_map(gadget_map_t *map)
{
    return (struct symtab_command *)find_load_command_in_map(map, LC_SYMTAB);
}

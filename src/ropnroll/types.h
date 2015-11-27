//
//  types.h
//  ropnroll_final
//
//  Created by jndok on 26/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#ifndef types_h
#define types_h

typedef struct kernel_fake_stack {
  uint32_t index;
  uint64_t stack[4096];
} kernel_fake_stack_t;

typedef struct gadget_map {
    void *map;
    size_t map_size;
} gadget_map_t;

typedef const char* gadget_t;
typedef const size_t gadget_size_t;

#endif /* types_h */

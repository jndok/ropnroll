//
//  test.s
//  ropnroll_final
//
//  Created by jndok on 14/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#if defined(__x86_64__)
.globl _test_gadget
_test_gadget:
    pop %rax;
    ret;
#elif defined(__i386__)
.globl _test_gadget
_test_gadget:
  pop %eax;
  ret;
#endif

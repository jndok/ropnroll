//
//  test.s
//  ropnroll_final
//
//  Created by jndok on 14/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#if defined(x64)
.globl _test_gadget
_test_gadget:
    pop %rax;
    ret;
#elif defined(x86)
.globl _test_gadget
_test_gadget:
  pop %eax;
  ret;
#endif

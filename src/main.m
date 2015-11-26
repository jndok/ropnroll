//
//  main.m
//  ropnroll_final
//
//  Created by jndok on 14/11/15.
//  Copyright © 2015 jndok. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <sys/ioctl.h>
#include <unistd.h>

#include "ropnroll/ropnroll_macros.h"
#include "ropnroll/ropnroll.h"

extern char test_gadget;

void center(char *s, int width)
{
    printf ("%*s\n", (int)(width / 2 + strlen(s) / 2), s);
}

void header(void) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  center("-=[ ropnroll v0.1.0 ]=-", w.ws_col);
  center("by @jndok", w.ws_col);

  printf("\n");

#if defined(__i386__)
  printf("[+] If you are seeing this, ropnroll compiled successfully! (x86)\n");
#elif defined(__x86_64__)
  printf("[+] If you are seeing this, ropnroll compiled successfully! (x64)\n");
#endif

  printf("\n");
}

int main(int argc, const char * argv[]) {

    header();

    return 0;
}

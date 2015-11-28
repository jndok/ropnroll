# ropnroll
_ropnroll_ is an helper library, designed for use in OS X exploits. I am using it for my kernel  stuff PoCs, but may be useful for other purposes as well.<br>The library is in early stages and there is much more to add and modify. For now it provides:

- Some kind of Mach-O parsing **(to be improved!)**
- Useful functions for ROP gadgets, i.e. find a single gadget or a group of gadgets in memory, dump gadgets in a human-readable format, find symbols in memory. **(to be improved!)**
- There are also various functions to be only used with kernel exploitation, find unslid KEXTs base address, find unslid kernel base (for symbol and gadgets resolution), find kernel slide (via `kas_info` with root privileges) **(to be improved!)**

_ropnroll_ is not very useful in its current state, it needs to be improved further. I will add more Mach-O parsing helpers, more ROP helpers (gadget macros, mapped images analysis, etc.), and also other kernel-exploitation-oriented stuff.

### how to use
Simply include the `ropnroll/` directory (found inside `src/` in this repo) in your project. Link against _capstone_.<br>You will need to `#include` the `ropnroll.h` and `ropnroll_macros.h` files to use the library.

### compile
You need _capstone_ to compile _ropnroll_. You can find the correct _capstone_ dylib (`libcapstone.3.dylib`) the `lib/` directory in this repository. The fat dylib is for both x86 and x64. You may need to manually replace the one located in `/usr/local/lib` if it doesn't compile.

## Mach-O analysis
_ropnroll_ provides functions for Mach-O binaries analysis, inside the `ropnroll/macho/` subdirectory.<br>These functions operate on `gadget_map_t` structures (note that the name will likely change in future), which are simple structs to hold together a mapped file and its size.<br>You can create a `gadget_map_t` for a file by simply calling `rnr_map_file_with_path` with the file path as an argument.

Once you have a map, use that to perform Mach-O analysis on the file. Example:
```
gadget_map_t *map=rnr_map_file_with_path("/System/Library/Kernels/kernel"); //map kernel

struct symtab_command *symcmd = find_symbol_table_in_map(map);
printf("Kernel has %d symbols defined.\n", symcmd->nsyms);
```

Obviously, more analysis function will be added to _ropnroll_ soon!

## ROP gadgets analysis
_ropnroll_ is primarily an exploitation library. So it provides a set of functions to discover and handle ROP gadgets to be used in ROP chains after successful stack pivoting.

You can find various macros inside `ropnroll/gadgets/rnr_gadgets.h`. These are _direct_ gadgets, meaning you can use these macros to directly find that sequence in a `gadget_map_t`. They are already there for you!<br>You can obviously use functions like `rnr_locate_gadget_in_map` and `rnr_locate_gadget_group_in_map` to find your own byte sequences.

### notes
Thanks to [@qwertyoruiop](http://twitter.com/qwertyoruiop) for help and his swag libraries (_lsym_ and _libxnuexp_)!

### help me out
You can contribute by issuing pull requests, and that would be very appreciated!

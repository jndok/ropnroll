# ropnroll
_ropnroll_ is an helper library, designed for use in OS X exploits. I am using it for my kernel  stuff PoCs, but may be useful for other purposes as well.<br>The library is in early stages and there is much more to add and modify. For now it provides:

- Some kind of Mach-O parsing **(to be improved!)**
- Useful functions for ROP gadgets, i.e. find a single gadget or a group of gadgets in memory, dump gadgets in a human-readable format, find symbols in memory. **(to be improved!)**
- There are also various functions to be only used with kernel exploitation, find unslid KEXTs base address, find unslid kernel base (for symbol and gadgets resolution), find kernel slide (via `kas_info` with root privileges) **(to be improved!)**

_ropnroll_ is not very useful in its current state, it needs to be improved further. I will add more Mach-O parsing helpers, more ROP helpers (gadget macros, mapped images analysis, etc.), and also other kernel-exploitation-oriented stuff.

### compile
You need _capstone_ to compile _ropnroll_. You can find the correct _capstone_ version il the `lib/` directory in this repository. The fat dylib is for both x86 and x64. You may need to manually replace the one located in `/usr/local/lib` if it doesn't compile.

### notes
Thanks to [@qwertyoruiop](http://twitter.com/qwertyoruiop) for help and his swag libraries (_lsym_ and _libxnuexp_)!

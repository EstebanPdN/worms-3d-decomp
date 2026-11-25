/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(hashnum)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaC_link = 0x802d2044;
luaG_runerror = 0x802cfb10;
luaM_realloc = 0x802d2108;
luaO_log2 = 0x802d231c;
luaO_rawequalObj = 0x802d23c0;
SECTIONS {
  .text.hashnum 0x802d5f84 : { *(.text.hashnum) }
  .text.luaH_mainposition 0x802d5fd4 : { *(.text.luaH_mainposition) }
  .text.arrayindex 0x802d60ac : { *(.text.arrayindex) }
  .text.luaH_index 0x802d6120 : { *(.text.luaH_index) }
  .text.luaH_next 0x802d61d8 : { *(.text.luaH_next) }
  .text.computesizes 0x802d6314 : { *(.text.computesizes) }
  .text.numuse 0x802d63dc : { *(.text.numuse) }
  .text.setarrayvector 0x802d6578 : { *(.text.setarrayvector) }
  .text.setnodevector 0x802d65f4 : { *(.text.setnodevector) }
  .text.resize 0x802d66cc : { *(.text.resize) }
  .text.rehash 0x802d687c : { *(.text.rehash) }
  .text.luaH_new 0x802d68d8 : { *(.text.luaH_new) }
  .text.luaH_free 0x802d6978 : { *(.text.luaH_free) }
  .text.newkey 0x802d69f0 : { *(.text.newkey) }
  .text.luaH_getany 0x802d6b24 : { *(.text.luaH_getany) }
  .text.luaH_getstr 0x802d6c48 : { *(.text.luaH_getstr) }
  .text.luaH_get 0x802d6ca0 : { *(.text.luaH_get) }
  .text.luaH_set 0x802d6d30 : { *(.text.luaH_set) }
  .text.luaH_setnum 0x802d6ddc : { *(.text.luaH_setnum) }
  .rodata 0x803da088 : { *(.rodata) }
  .sdata 0x804b1968 (NOLOAD) : {
    . = 0x0; luaO_nilobject = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

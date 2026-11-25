/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaT_init)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaH_getstr = 0x802d6c48;
luaS_newlstr = 0x802d5e30;
strlen = 0x802ef9c0;
SECTIONS {
  .text.luaT_init 0x802d6e68 : { *(.text.luaT_init) }
  .text.luaT_gettm 0x802d6eec : { *(.text.luaT_gettm) }
  .text.luaT_gettmbyobj 0x802d6f44 : { *(.text.luaT_gettmbyobj) }
  .rodata 0x803da108 : { *(.rodata) }
  .sdata 0x804b1968 (NOLOAD) : {
    . = 0x0; luaO_nilobject = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(reallymarkobject)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_call = 0x802d0660;
luaD_reallocCI = 0x802cfeb4;
luaD_reallocstack = 0x802cfe48;
luaE_freethread = 0x802d5ab0;
luaF_freeclosure = 0x802d0f0c;
luaF_freeproto = 0x802d0e40;
luaH_free = 0x802d6978;
luaM_realloc = 0x802d2108;
luaS_resize = 0x802d5c6c;
luaT_gettm = 0x802d6eec;
strchr = 0x802ef198;
SECTIONS {
  .text.reallymarkobject 0x802d0fd4 : { *(.text.reallymarkobject) }
  .text.marktmu 0x802d1080 : { *(.text.marktmu) }
  .text.luaC_separateudata 0x802d10dc : { *(.text.luaC_separateudata) }
  .text.removekey 0x802d11b4 : { *(.text.removekey) }
  .text.traversetable 0x802d11d4 : { *(.text.traversetable) }
  .text.traverseproto 0x802d13fc : { *(.text.traverseproto) }
  .text.traverseclosure 0x802d1544 : { *(.text.traverseclosure) }
  .text.checkstacksizes 0x802d1670 : { *(.text.checkstacksizes) }
  .text.traversestack 0x802d1710 : { *(.text.traversestack) }
  .text.propagatemarks 0x802d1814 : { *(.text.propagatemarks) }
  .text.valismarked 0x802d18cc : { *(.text.valismarked) }
  .text.cleartablekeys 0x802d1914 : { *(.text.cleartablekeys) }
  .text.cleartablevalues 0x802d1998 : { *(.text.cleartablevalues) }
  .text.freeobj 0x802d1a58 : { *(.text.freeobj) }
  .text.sweeplist 0x802d1b08 : { *(.text.sweeplist) }
  .text.sweepstrings 0x802d1b88 : { *(.text.sweepstrings) }
  .text.checkSizes 0x802d1c08 : { *(.text.checkSizes) }
  .text.do1gcTM 0x802d1cb8 : { *(.text.do1gcTM) }
  .text.luaC_callGCTM 0x802d1d54 : { *(.text.luaC_callGCTM) }
  .text.luaC_sweep 0x802d1e10 : { *(.text.luaC_sweep) }
  .text.markroot 0x802d1e78 : { *(.text.markroot) }
  .text.mark 0x802d1f30 : { *(.text.mark) }
  .text.luaC_link 0x802d2044 : { *(.text.luaC_link) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

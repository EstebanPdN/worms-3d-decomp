/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(unexpectedEOZ)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaF_newproto = 0x802d0da4;
luaG_checkcode = 0x802cf590;
luaG_runerror = 0x802cfb10;
luaM_realloc = 0x802d2108;
luaS_newlstr = 0x802d5e30;
luaZ_fill = 0x802d9a50;
luaZ_openspace = 0x802d9c08;
luaZ_read = 0x802d9b48;
SECTIONS {
  .text.unexpectedEOZ 0x802d6f9c : { *(.text.unexpectedEOZ) }
  .text.ezgetc 0x802d6fd0 : { *(.text.ezgetc) }
  .text.ezread 0x802d704c : { *(.text.ezread) }
  .text.LoadBlock 0x802d708c : { *(.text.LoadBlock) }
  .text.LoadVector 0x802d70fc : { *(.text.LoadVector) }
  .text.LoadInt 0x802d7198 : { *(.text.LoadInt) }
  .text.LoadSize 0x802d71f4 : { *(.text.LoadSize) }
  .text.LoadNumber 0x802d7220 : { *(.text.LoadNumber) }
  .text.LoadString 0x802d724c : { *(.text.LoadString) }
  .text.LoadCode 0x802d72bc : { *(.text.LoadCode) }
  .text.LoadLocals 0x802d7324 : { *(.text.LoadLocals) }
  .text.LoadLines 0x802d73c8 : { *(.text.LoadLines) }
  .text.LoadUpvalues 0x802d7430 : { *(.text.LoadUpvalues) }
  .text.LoadConstants 0x802d74d4 : { *(.text.LoadConstants) }
  .text.LoadFunction 0x802d7618 : { *(.text.LoadFunction) }
  .text.LoadSignature 0x802d770c : { *(.text.LoadSignature) }
  .text.TestSize 0x802d7788 : { *(.text.TestSize) }
  .text.LoadHeader 0x802d77e8 : { *(.text.LoadHeader) }
  .text.LoadChunk 0x802d79b0 : { *(.text.LoadChunk) }
  .text.luaU_undump 0x802d79e8 : { *(.text.luaU_undump) }
  .rodata 0x803da22c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

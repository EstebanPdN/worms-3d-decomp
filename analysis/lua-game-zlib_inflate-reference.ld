/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(inflateReset)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
adler32 = 0x802c8a5c;
inflate_blocks = 0x802c8d70;
inflate_blocks_free = 0x802c98e0;
inflate_blocks_new = 0x802c8cb8;
inflate_blocks_reset = 0x802c8be0;
zcalloc = 0x802c8a10;
zcfree = 0x802c8a38;
SECTIONS {
  .text.inflateReset 0x802c8208 : { *(.text.inflateReset) }
  .text.inflateEnd 0x802c8280 : { *(.text.inflateEnd) }
  .text.inflateInit2_ 0x802c8304 : { *(.text.inflateInit2_) }
  .text.inflate 0x802c8468 : { *(.text.inflate) }
  .rodata 0x803d8e58 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15a_refresh_follow_800f02a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fade_800f09d0 = 0x800f09d0;
index_800fc6dc = 0x800fc6dc;
integer_80178c48 = 0x80178c48;
step_800f0a70 = 0x800f0a70;
SECTIONS {
  .text.w3d_cx15a_refresh_follow_800f02a8 0x800f02a8 : { *(.text.w3d_cx15a_refresh_follow_800f02a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

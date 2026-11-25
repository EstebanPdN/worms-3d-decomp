/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_query_position_800e25dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a3190 = 0x801a3190;
fn_80343740 = 0x80343740;
SECTIONS {
  .text.w3d_s20_query_position_800e25dc 0x800e25dc : { *(.text.w3d_s20_query_position_800e25dc) }
  .text.w3d_s20_apply_indexed_801a3164 0x801a3164 : { *(.text.w3d_s20_apply_indexed_801a3164) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

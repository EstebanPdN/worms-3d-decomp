/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_apply_link_8016b5a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016b488 = 0x8016b488;
fn_801ab98c = 0x801ab98c;
SECTIONS {
  .text.w3d_s20_apply_link_8016b5a0 0x8016b5a0 : { *(.text.w3d_s20_apply_link_8016b5a0) }
  .text.w3d_s20_remap_and_dispatch_801aba00 0x801aba00 : { *(.text.w3d_s20_remap_and_dispatch_801aba00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

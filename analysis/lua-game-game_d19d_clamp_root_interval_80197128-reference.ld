/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19d_clamp_root_interval_80197128)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d19d_clamp_root_interval_80197128 0x80197128 : { *(.text.d19d_clamp_root_interval_80197128) }
  .rodata 0x803a84f8 : { *(.rodata) }
  .sdata 0x804ab6e4 (NOLOAD) : {
    . = 0x0; lbl_804ab6e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

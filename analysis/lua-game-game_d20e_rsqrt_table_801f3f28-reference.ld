/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d20e_rsqrt_table_801f3f28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe220 = 0x801fe220;
fn_802e82c0 = 0x802e82c0;
lbl_803b0ec0 = 0x803b0ec0;
SECTIONS {
  .text.w3d_d20e_rsqrt_table_801f3f28 0x801f3f28 : { *(.text.w3d_d20e_rsqrt_table_801f3f28) }
  .sdata 0x804ab8d0 (NOLOAD) : {
    . = 0x0; lbl_804ab8d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

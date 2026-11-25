/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_8016df70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801cb41c = 0x801cb41c;
lbl_80412680 = 0x80412680;
lbl_80416140 = 0x80416140;
SECTIONS {
  .text.w3d_construct_8016df70 0x8016df70 : { *(.text.w3d_construct_8016df70) }
  .text.w3d_construct_8017892c 0x8017892c : { *(.text.w3d_construct_8017892c) }
  .text.w3d_construct_801cbf98 0x801cbf98 : { *(.text.w3d_construct_801cbf98) }
  .text.w3d_construct_801f2678 0x801f2678 : { *(.text.w3d_construct_801f2678) }
  .text.w3d_construct_802109dc 0x802109dc : { *(.text.w3d_construct_802109dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

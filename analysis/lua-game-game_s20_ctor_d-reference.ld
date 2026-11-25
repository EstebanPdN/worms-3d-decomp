/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_scaled_801bd6b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801bd510 = 0x801bd510;
fn_801ea0ec = 0x801ea0ec;
lbl_803abba0 = 0x803abba0;
lbl_80415190 = 0x80415190;
lbl_80415ee8 = 0x80415ee8;
SECTIONS {
  .text.w3d_s20_construct_scaled_801bd6b8 0x801bd6b8 : { *(.text.w3d_s20_construct_scaled_801bd6b8) }
  .text.w3d_s20_construct_flagged_801cdd48 0x801cdd48 : { *(.text.w3d_s20_construct_flagged_801cdd48) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

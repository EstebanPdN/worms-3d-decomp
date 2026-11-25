/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_release_pair_800e77dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800ae9ac = 0x800ae9ac;
fn_800ae9b4 = 0x800ae9b4;
fn_800b0100 = 0x800b0100;
fn_80164fc8 = 0x80164fc8;
fn_80181814 = 0x80181814;
lbl_8039f6ec = 0x8039f6ec;
SECTIONS {
  .text.w3d_s20_release_pair_800e77dc 0x800e77dc : { *(.text.w3d_s20_release_pair_800e77dc) }
  .text.w3d_s20_apply_handle_pair_8013a048 0x8013a048 : { *(.text.w3d_s20_apply_handle_pair_8013a048) }
  .text.w3d_s20_state_in_set_8013d88c 0x8013d88c : { *(.text.w3d_s20_state_in_set_8013d88c) }
  .sdata 0x804ab17c (NOLOAD) : {
    . = 0x0; lbl_804ab17c = .;
    . = 0x4; lbl_804ab180 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

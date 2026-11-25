/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_destroy_two_bases_802af41c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ff2c = 0x8015ff2c;
fn_802afc40 = 0x802afc40;
lbl_8041c590 = 0x8041c590;
lbl_8041c5e0 = 0x8041c5e0;
lbl_8041c7d0 = 0x8041c7d0;
lbl_8041c820 = 0x8041c820;
SECTIONS {
  .text.w3d_destroy_two_bases_802af41c 0x802af41c : { *(.text.w3d_destroy_two_bases_802af41c) }
  .text.w3d_destroy_two_bases_802ba45c 0x802ba45c : { *(.text.w3d_destroy_two_bases_802ba45c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

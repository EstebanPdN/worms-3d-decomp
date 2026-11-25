/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801ede8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801EE1E4 = 0x801ee1e4;
fn_801FE1F8 = 0x801fe1f8;
fn_802098FC = 0x802098fc;
lbl_80417778 = 0x80417778;
SECTIONS {
  .text.w3d_auto_801ede8c 0x801ede8c : { *(.text.w3d_auto_801ede8c) }
  .text.w3d_auto_801edec0 0x801edec0 : { *(.text.w3d_auto_801edec0) }
  .sdata 0x804b05a0 (NOLOAD) : {
    . = 0x0; lbl_804B05A0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

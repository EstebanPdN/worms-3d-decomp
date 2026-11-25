/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801ab4c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801E5FD4 = 0x801e5fd4;
fn_801E65A0 = 0x801e65a0;
fn_80208FD8 = 0x80208fd8;
fn_8020B680 = 0x8020b680;
fn_8020B884 = 0x8020b884;
fn_80218D10 = 0x80218d10;
fn_80219264 = 0x80219264;
lbl_804167F0 = 0x804167f0;
SECTIONS {
  .text.w3d_auto_801ab4c4 0x801ab4c4 : { *(.text.w3d_auto_801ab4c4) }
  .text.w3d_auto_801b4938 0x801b4938 : { *(.text.w3d_auto_801b4938) }
  .text.w3d_auto_801e64c0 0x801e64c0 : { *(.text.w3d_auto_801e64c0) }
  .text.w3d_auto_80208ce0 0x80208ce0 : { *(.text.w3d_auto_80208ce0) }
  .text.w3d_auto_802188f8 0x802188f8 : { *(.text.w3d_auto_802188f8) }
  .text.w3d_auto_80218f98 0x80218f98 : { *(.text.w3d_auto_80218f98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

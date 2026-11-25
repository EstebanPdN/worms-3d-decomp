/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_dtor_802afc40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1f8 = 0x801fe1f8;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
w3d_vtable_8041c610 = 0x8041c610;
SECTIONS {
  .text.w3d_dtor_802afc40 0x802afc40 : { *(.text.w3d_dtor_802afc40) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

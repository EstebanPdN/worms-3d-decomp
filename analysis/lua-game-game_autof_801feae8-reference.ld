/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801feae8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020D8F8 = 0x8020d8f8;
fn_8020DA90 = 0x8020da90;
fn_802ED89C = 0x802ed89c;
SECTIONS {
  .text.w3d_auto_801feae8 0x801feae8 : { *(.text.w3d_auto_801feae8) }
  .text.w3d_auto_801feb48 0x801feb48 : { *(.text.w3d_auto_801feb48) }
  .text.w3d_auto_801fec04 0x801fec04 : { *(.text.w3d_auto_801fec04) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

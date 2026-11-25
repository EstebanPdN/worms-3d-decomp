/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8013f4dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC6DC = 0x800fc6dc;
fn_800FC7F8 = 0x800fc7f8;
fn_801492EC = 0x801492ec;
fn_80153F58 = 0x80153f58;
fn_80157A30 = 0x80157a30;
SECTIONS {
  .text.w3d_auto_8013f4dc 0x8013f4dc : { *(.text.w3d_auto_8013f4dc) }
  .text.w3d_auto_8014e960 0x8014e960 : { *(.text.w3d_auto_8014e960) }
  .text.w3d_auto_8014f8c0 0x8014f8c0 : { *(.text.w3d_auto_8014f8c0) }
  .text.w3d_auto_8014fedc 0x8014fedc : { *(.text.w3d_auto_8014fedc) }
  .text.w3d_auto_80151128 0x80151128 : { *(.text.w3d_auto_80151128) }
  .text.w3d_auto_80153f58 0x80153f58 : { *(.text.w3d_auto_80153f58) }
  .text.w3d_auto_80155760 0x80155760 : { *(.text.w3d_auto_80155760) }
  .text.w3d_auto_80156f68 0x80156f68 : { *(.text.w3d_auto_80156f68) }
  .sdata 0x804ab3b0 (NOLOAD) : {
    . = 0x0; lbl_804AB3B0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

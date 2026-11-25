/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_reset_sequence_801fe3b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802f7b40 = 0x802f7b40;
fn_802fb7ac = 0x802fb7ac;
fn_802fe898 = 0x802fe898;
fn_802feb50 = 0x802feb50;
fn_80301ba0 = 0x80301ba0;
fn_80303964 = 0x80303964;
fn_803049e8 = 0x803049e8;
fn_80304b84 = 0x80304b84;
fn_803085a0 = 0x803085a0;
fn_80331a40 = 0x80331a40;
str_803b2974 = 0x803b2974;
SECTIONS {
  .text.w3d_cx16b_reset_sequence_801fe3b0 0x801fe3b0 : { *(.text.w3d_cx16b_reset_sequence_801fe3b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32k_glyph_uv_table_80263608)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ae3c = 0x8015ae3c;
fn_80171ee0 = 0x80171ee0;
fn_80171f90 = 0x80171f90;
fn_80171fa0 = 0x80171fa0;
fn_80171ff8 = 0x80171ff8;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80343808 = 0x80343808;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d32k_glyph_uv_table_80263608 0x80263608 : { *(.text.w3d_d32k_glyph_uv_table_80263608) }
  .rodata 0x803cafb8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

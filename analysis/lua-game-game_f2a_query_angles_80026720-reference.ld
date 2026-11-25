/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f2a_query_angles_80026720)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc6dc = 0x800fc6dc;
fn_80178c48 = 0x80178c48;
fn_803426b4 = 0x803426b4;
lbl_8036ca58 = 0x8036ca58;
SECTIONS {
  .text.w3d_f2a_query_angles_80026720 0x80026720 : { *(.text.w3d_f2a_query_angles_80026720) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

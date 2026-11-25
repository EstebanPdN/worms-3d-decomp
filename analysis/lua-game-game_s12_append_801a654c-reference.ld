/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_append_value_801a654c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80212fd4__FUi = 0x80212fd4;
fn_802134fc__FPv = 0x802134fc;
memcpy = 0x802eee50;
SECTIONS {
  .text.w3d_s12_append_value_801a654c 0x801a654c : { *(.text.w3d_s12_append_value_801a654c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

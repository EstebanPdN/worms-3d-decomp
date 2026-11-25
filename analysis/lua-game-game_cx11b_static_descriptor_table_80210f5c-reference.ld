/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_static_descriptor_table_80210f5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_802eefe0 = 0x802eefe0;
table_80463c10 = 0x80463c10;
type_8040c9a0 = 0x8040c9a0;
type_804138b0 = 0x804138b0;
SECTIONS {
  .text.w3d_cx11b_static_descriptor_table_80210f5c 0x80210f5c : { *(.text.w3d_cx11b_static_descriptor_table_80210f5c) }
  .sdata 0x804b06bc (NOLOAD) : {
    . = 0x0; guard_804b06bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

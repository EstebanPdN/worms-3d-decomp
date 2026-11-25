/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16a_apply_selected_800a1608)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_80173df0 = 0x80173df0;
cast_8034357c = 0x8034357c;
read_800fd388 = 0x800fd388;
select_80178c48 = 0x80178c48;
SECTIONS {
  .text.w3d_cx16a_apply_selected_800a1608 0x800a1608 : { *(.text.w3d_cx16a_apply_selected_800a1608) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

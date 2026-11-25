/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_set_material_colors_8016b9ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803096a4 = 0x803096a4;
fn_8030972c = 0x8030972c;
SECTIONS {
  .text.d29j_set_material_colors_8016b9ec 0x8016b9ec : { *(.text.d29j_set_material_colors_8016b9ec) }
  .rodata 0x803a5674 : { *(.rodata) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

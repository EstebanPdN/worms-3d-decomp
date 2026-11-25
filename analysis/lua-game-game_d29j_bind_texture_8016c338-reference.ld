/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_bind_texture_8016c338)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016803c = 0x8016803c;
fn_8016c4f4 = 0x8016c4f4;
fn_8030a21c = 0x8030a21c;
wrap_803a569c = 0x803a569c;
SECTIONS {
  .text.d29j_bind_texture_8016c338 0x8016c338 : { *(.text.d29j_bind_texture_8016c338) }
  .sdata 0x804ab544 (NOLOAD) : {
    . = 0x0; current_804ab544 = .;
    . = 0x6340; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

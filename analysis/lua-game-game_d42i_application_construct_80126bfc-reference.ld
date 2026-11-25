/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42i_application_construct_80126bfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015c4e0 = 0x8015c4e0;
string_default_803426b8 = 0x803426b8;
vtable_80410c48 = 0x80410c48;
SECTIONS {
  .text.d42i_application_construct_80126bfc 0x80126bfc : { *(.text.d42i_application_construct_80126bfc) }
  .rodata 0x8039bc74 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

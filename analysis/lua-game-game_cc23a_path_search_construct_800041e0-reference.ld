/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_path_search_construct_800041e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80004394 = 0x80004394;
lbl_8040cb10 = 0x8040cb10;
SECTIONS {
  .text.cc23a_path_search_construct_800041e0 0x800041e0 : { *(.text.cc23a_path_search_construct_800041e0) }
  .sdata 0x804aa54c (NOLOAD) : {
    . = 0x0; lbl_804aa54c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

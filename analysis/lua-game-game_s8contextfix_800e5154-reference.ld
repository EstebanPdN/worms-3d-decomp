/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_destroy_references_800e5154)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C56B8 = 0x800c56b8;
fn_800E5BB8 = 0x800e5bb8;
fn_801628EC = 0x801628ec;
lbl_804100B8 = 0x804100b8;
SECTIONS {
  .text.s8_destroy_references_800e5154 0x800e5154 : { *(.text.s8_destroy_references_800e5154) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; lbl_804AAECC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

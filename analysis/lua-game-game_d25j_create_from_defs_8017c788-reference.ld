/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25j_create_from_defs_8017c788)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801702b8 = 0x801702b8;
fn_8017c464 = 0x8017c464;
fn_80187158 = 0x80187158;
fn_8020b680 = 0x8020b680;
key_80411ff8 = 0x80411ff8;
key_80412d98 = 0x80412d98;
SECTIONS {
  .text.d25j_create_from_defs_8017c788 0x8017c788 : { *(.text.d25j_create_from_defs_8017c788) }
  .sdata 0x804ab5e8 (NOLOAD) : {
    . = 0x0; stamp_804ab5e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

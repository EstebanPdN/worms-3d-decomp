/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_copy_shared_ref_80182498)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341348 = 0x80341348;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
SECTIONS {
  .text.d29j_copy_shared_ref_80182498 0x80182498 : { *(.text.d29j_copy_shared_ref_80182498) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

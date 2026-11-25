/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_shared_name_pair_802c4498)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c4 = 0x8020c5c4;
fn_802c459c = 0x802c459c;
fn_802ef234 = 0x802ef234;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_set_shared_name_pair_802c4498 0x802c4498 : { *(.text.w3d_set_shared_name_pair_802c4498) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

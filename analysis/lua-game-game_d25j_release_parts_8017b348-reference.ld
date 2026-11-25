/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25j_release_parts_8017b348)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801859f8 = 0x801859f8;
fn_801ef380 = 0x801ef380;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
SECTIONS {
  .text.d25j_release_parts_8017b348 0x8017b348 : { *(.text.d25j_release_parts_8017b348) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; service_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

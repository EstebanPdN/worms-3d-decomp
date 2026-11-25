/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27j_add_record_8019217c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80197ce4 = 0x80197ce4;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_8034f190 = 0x8034f190;
w3d_auto_801907a8 = 0x801907a8;
w3d_auto_801907d0 = 0x801907d0;
SECTIONS {
  .text.d27j_add_record_8019217c 0x8019217c : { *(.text.d27j_add_record_8019217c) }
  .text.d27j_add_record_sized_801929c0 0x801929c0 : { *(.text.d27j_add_record_sized_801929c0) }
  .sdata 0x804ab6f4 (NOLOAD) : {
    . = 0x0; building_804ab6f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

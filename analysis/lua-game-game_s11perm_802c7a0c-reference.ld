/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802c7a0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020C5C0 = 0x8020c5c0;
fn_8020C5C4 = 0x8020c5c4;
fn_802C7894 = 0x802c7894;
fn_802C78F4 = 0x802c78f4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
SECTIONS {
  .text.w3d_auto_802c7a0c 0x802c7a0c : { *(.text.w3d_auto_802c7a0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

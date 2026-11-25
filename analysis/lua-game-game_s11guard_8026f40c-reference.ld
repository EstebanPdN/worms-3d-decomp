/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026f40c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026ED00 = 0x8026ed00;
fn_8026F9D0 = 0x8026f9d0;
fn_8026FC98 = 0x8026fc98;
fn_80296518 = 0x80296518;
fn_802B0990 = 0x802b0990;
fn_802BC8B4 = 0x802bc8b4;
SECTIONS {
  .text.w3d_auto_8026f40c 0x8026f40c : { *(.text.w3d_auto_8026f40c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

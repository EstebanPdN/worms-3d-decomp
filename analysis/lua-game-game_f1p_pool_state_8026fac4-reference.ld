/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pool_state_8026fac4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026f6e0 = 0x8026f6e0;
fn_8026fa7c = 0x8026fa7c;
fn_802bc71c = 0x802bc71c;
fn_802bc778 = 0x802bc778;
SECTIONS {
  .text.w3d_pool_state_8026fac4 0x8026fac4 : { *(.text.w3d_pool_state_8026fac4) }
  .rodata 0x803cbf28 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

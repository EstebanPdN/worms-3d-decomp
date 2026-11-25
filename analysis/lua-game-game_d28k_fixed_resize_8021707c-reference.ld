/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_fixed_resize_8021707c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80216c4c = 0x80216c4c;
fn_80216e7c = 0x80216e7c;
fn_80216f5c = 0x80216f5c;
lbl_8040077c = 0x8040077c;
SECTIONS {
  .text.w3d_d28k_fixed_resize_8021707c 0x8021707c : { *(.text.w3d_d28k_fixed_resize_8021707c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

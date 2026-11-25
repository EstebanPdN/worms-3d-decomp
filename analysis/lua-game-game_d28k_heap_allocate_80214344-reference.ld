/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_heap_allocate_80214344)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80213d90 = 0x80213d90;
fn_80213f98 = 0x80213f98;
lbl_80400768 = 0x80400768;
lbl_8040077c = 0x8040077c;
SECTIONS {
  .text.w3d_d28k_heap_allocate_80214344 0x80214344 : { *(.text.w3d_d28k_heap_allocate_80214344) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

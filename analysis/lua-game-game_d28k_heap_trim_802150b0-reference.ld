/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_heap_trim_802150b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80213d90 = 0x80213d90;
fn_80213f98 = 0x80213f98;
lbl_80400768 = 0x80400768;
SECTIONS {
  .text.w3d_d28k_heap_trim_802150b0 0x802150b0 : { *(.text.w3d_d28k_heap_trim_802150b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

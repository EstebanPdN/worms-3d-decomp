/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_disc_screen_destroy_800c6f20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_disc_vtable_8040faa8 = 0x8040faa8;
w3d_service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.w3d_disc_screen_destroy_800c6f20 0x800c6f20 : { *(.text.w3d_disc_screen_destroy_800c6f20) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

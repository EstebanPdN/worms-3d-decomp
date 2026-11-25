/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_pool_owner_destroy_800c8630)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_shared_8043eda4 = 0x8043eda4;
w3d_vtable_8040fb38 = 0x8040fb38;
SECTIONS {
  .text.w3d_k10a_pool_owner_destroy_800c8630 0x800c8630 : { *(.text.w3d_k10a_pool_owner_destroy_800c8630) }
  .sdata 0x804b1794 (NOLOAD) : {
    . = 0x0; w3d_owner_804b1794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

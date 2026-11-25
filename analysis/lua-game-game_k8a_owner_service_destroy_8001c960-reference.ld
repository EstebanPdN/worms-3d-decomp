/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_owner_service_destroy_8001c960)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s19_release_owner_8001cac4 = 0x8001cac4;
w3d_handle_storage_release = 0x802134fc;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8040dac8 = 0x8040dac8;
SECTIONS {
  .text.w3d_k8a_owner_service_destroy_8001c960 0x8001c960 : { *(.text.w3d_k8a_owner_service_destroy_8001c960) }
  .sdata 0x804b1758 (NOLOAD) : {
    . = 0x0; w3d_global_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

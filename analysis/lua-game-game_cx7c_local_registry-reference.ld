/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7c_local_registry_8035a3a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx7c_register_exit_802ed7e0 = 0x802ed7e0;
cx7c_registry_cleanup_801fdb6c = 0x801fdb6c;
cx7c_registry_construct_8016df70 = 0x8016df70;
cx7c_storage_8045e9c8 = 0x8045e9c8;
SECTIONS {
  .text.w3d_cx7c_local_registry_8035a3a8 0x8035a3a8 : { *(.text.w3d_cx7c_local_registry_8035a3a8) }
  .sdata 0x804b060c (NOLOAD) : {
    . = 0x0; cx7c_guard_804b060c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

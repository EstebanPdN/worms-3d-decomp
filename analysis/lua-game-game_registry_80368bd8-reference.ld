/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_registry_80368bd8_unlink)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_registry_list_80368bd8 = 0x80368bd8;
w3d_registry_object_construct_802c5d3c = 0x802c5d3c;
w3d_registry_object_destroy_802c5e10 = 0x802c5e10;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_registry_80368bd8_unlink 0x802c5c24 : { *(.text.w3d_registry_80368bd8_unlink) }
  .text.w3d_registry_80368bd8_create 0x802c5c68 : { *(.text.w3d_registry_80368bd8_create) }
  .text.w3d_registry_80368bd8_release 0x802c5cc8 : { *(.text.w3d_registry_80368bd8_release) }
  .text.w3d_registry_80368bd8_retain 0x802c5d24 : { *(.text.w3d_registry_80368bd8_retain) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

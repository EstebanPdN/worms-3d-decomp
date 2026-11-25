/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_registry_remove)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_registry_entry_clear = 0x802074c4;
w3d_actor_registry_observer_type = 0x8045edb8;
SECTIONS {
  .text.w3d_actor_registry_remove 0x802075d4 : { *(.text.w3d_actor_registry_remove) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

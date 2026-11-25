/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_registry_entry_clear)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_release = 0x80209920;
SECTIONS {
  .text.w3d_actor_registry_entry_clear 0x802074c4 : { *(.text.w3d_actor_registry_entry_clear) }
  .sdata 0x804b0644 (NOLOAD) : {
    . = 0x0; w3d_actor_registry_value_heap = .;
    . = 0x8; w3d_actor_registry_entry_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

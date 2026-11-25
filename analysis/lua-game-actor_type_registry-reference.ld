/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_type_first)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_actor_type_first 0x8020fe00 : { *(.text.w3d_actor_type_first) }
  .text.w3d_actor_type_next 0x8020fe18 : { *(.text.w3d_actor_type_next) }
  .text.w3d_actor_types_first 0x8020ff3c : { *(.text.w3d_actor_types_first) }
  .sdata 0x804b1904 (NOLOAD) : {
    . = 0x0; w3d_actor_type_registry = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

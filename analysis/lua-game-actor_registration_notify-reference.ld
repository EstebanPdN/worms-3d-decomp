/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_registration_notify)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_registered_message_methods = 0x8040db38;
w3d_message_allocate = 0x801613f0;
SECTIONS {
  .text.w3d_actor_registration_notify 0x8034b418 : { *(.text.w3d_actor_registration_notify) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_storage = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

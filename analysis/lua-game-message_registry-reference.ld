/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_message_find_name)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_message_find_name 0x80161ffc : { *(.text.w3d_message_find_name) }
  .text.w3d_message_post_current 0x8016239c : { *(.text.w3d_message_post_current) }
  .sdata 0x804ab4a0 (NOLOAD) : {
    . = 0x0; w3d_message_context = .;
    . = 0x4; w3d_message_name_slots = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

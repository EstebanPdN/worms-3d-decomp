/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_message_dispatch)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_message_dispatch_core = 0x80163510;
w3d_message_report = 0x80347324;
SECTIONS {
  .text.w3d_message_dispatch 0x8015fc38 : { *(.text.w3d_message_dispatch) }
  .text.w3d_message_register 0x80161e38 : { *(.text.w3d_message_register) }
  .text.w3d_message_hash_slot 0x80161f00 : { *(.text.w3d_message_hash_slot) }
  .text.w3d_message_find_id 0x80161f54 : { *(.text.w3d_message_find_id) }
  .text.w3d_message_find_name 0x80161ffc : { *(.text.w3d_message_find_name) }
  .text.w3d_message_post_current 0x8016239c : { *(.text.w3d_message_post_current) }
  .rodata 0x803a4910 : { *(.rodata) }
  .sdata 0x804ab49c (NOLOAD) : {
    . = 0x0; w3d_message_name_capacity = .;
    . = 0x4; w3d_message_context = .;
    . = 0x8; w3d_message_name_slots = .;
    . = 0x51a4; w3d_message_diagnostics = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxa_motion_message_8002165c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
construct_80131a84 = 0x80131a84;
context_80165254 = 0x80165254;
post_8016239c = 0x8016239c;
reserve_801613f0 = 0x801613f0;
SECTIONS {
  .text.cxa_motion_message_8002165c 0x8002165c : { *(.text.cxa_motion_message_8002165c) }
  .text.cxa_motion_message_80021c60 0x80021c60 : { *(.text.cxa_motion_message_80021c60) }
  .text.cxa_motion_message_80021d8c 0x80021d8c : { *(.text.cxa_motion_message_80021d8c) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

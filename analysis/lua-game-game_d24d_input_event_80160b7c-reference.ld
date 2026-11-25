/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_input_event_80160b7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_arena_alloc_801613f0 = 0x801613f0;
d24d_input_target_8016559c = 0x8016559c;
d24d_key_press_80160558 = 0x80160558;
d24d_key_release_801605c0 = 0x801605c0;
d24d_message_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.d24d_input_event_80160b7c 0x80160b7c : { *(.text.d24d_input_event_80160b7c) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; d24d_arena_804b1754 = .;
    . = 0x9c; d24d_input_state_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

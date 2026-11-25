/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_idle_watch_80021e4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_cached_message_id = 0x8015f5a0;
w3d_engine_get_context = 0x80165254;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_string_8036c014 = 0x8036c014;
w3d_string_8036c178 = 0x8036c178;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_idle_watch_80021e4c 0x80021e4c : { *(.text.k5a_idle_watch_80021e4c) }
  .sdata 0x804aca14 (NOLOAD) : {
    . = 0x0; w3d_message_804aca14 = .;
    . = 0x8; w3d_message_804aca1c = .;
    . = 0x4d40; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

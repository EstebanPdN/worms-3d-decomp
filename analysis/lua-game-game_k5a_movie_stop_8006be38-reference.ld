/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_movie_stop_8006be38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a7e14 = 0x800a7e14;
FUN_801613f0 = 0x801613f0;
w3d_app_leave_801298cc = 0x801298cc;
w3d_auto_800fc230 = 0x800fc230;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_runtime_is_paused = 0x8015ccbc;
w3d_string_8037bb14 = 0x8037bb14;
w3d_string_8037bea0 = 0x8037bea0;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.k5a_movie_stop_8006be38 0x8006be38 : { *(.text.k5a_movie_stop_8006be38) }
  .sdata 0x804ad734 (NOLOAD) : {
    . = 0x0; w3d_message_804ad734 = .;
    . = 0xd0; w3d_message_804ad804 = .;
    . = 0x108; w3d_message_804ad83c = .;
    . = 0x4020; w3d_message_pool_804b1754 = .;
    . = 0x4054; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

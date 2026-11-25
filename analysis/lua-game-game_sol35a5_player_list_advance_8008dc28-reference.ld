/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a5_player_list_advance_8008dc28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801613f0 = 0x801613f0;
sol35a5_copy_802eee50 = 0x802eee50;
w3d_auto_80023128 = 0x80023128;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_post_current = 0x8016239c;
w3d_player_list_selection_8008dd4c = 0x8008dd4c;
w3d_player_list_timer_active_8008dd18 = 0x8008dd18;
w3d_target_id_message_801190b4 = 0x801190b4;
SECTIONS {
  .text.sol35a5_player_list_advance_8008dc28 0x8008dc28 : { *(.text.sol35a5_player_list_advance_8008dc28) }
  .sdata 0x804aa7d4 (NOLOAD) : {
    . = 0x0; w3d_list_804aa7d4 = .;
    . = 0x3548; w3d_message_cache_804add1c = .;
    . = 0x6f80; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

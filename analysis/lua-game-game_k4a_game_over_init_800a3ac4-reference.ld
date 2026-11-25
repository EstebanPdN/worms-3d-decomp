/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_game_over_init_800a3ac4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a3d0c = 0x800a3d0c;
FUN_800a4038 = 0x800a4038;
FUN_800fd62c = 0x800fd62c;
s8_visibility_800a3c24 = 0x800a3c24;
w3d_cached_message_id = 0x8015f5a0;
w3d_str_80380d14 = 0x80380d14;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.k4a_game_over_init_800a3ac4 0x800a3ac4 : { *(.text.k4a_game_over_init_800a3ac4) }
  .sdata 0x804ae18c (NOLOAD) : {
    . = 0x0; w3d_message_804ae18c = .;
    . = 0x8; w3d_message_804ae194 = .;
    . = 0x10; w3d_message_804ae19c = .;
    . = 0x18; w3d_message_804ae1a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

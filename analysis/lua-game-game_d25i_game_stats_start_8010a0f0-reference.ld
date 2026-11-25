/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_game_stats_start_8010a0f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
as_table_80341584 = 0x80341584;
cached_id_8015f5a0 = 0x8015f5a0;
clear_counts_80109ae4 = 0x80109ae4;
n_80399ce8 = 0x80399ce8;
n_80399cfc = 0x80399cfc;
n_80399d20 = 0x80399d20;
n_80399d38 = 0x80399d38;
read_int_800fc230 = 0x800fc230;
read_setting_800fc1b0 = 0x800fc1b0;
read_text_800fc550 = 0x800fc550;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
table_get_80179598 = 0x80179598;
SECTIONS {
  .text.d25i_game_stats_start_8010a0f0 0x8010a0f0 : { *(.text.d25i_game_stats_start_8010a0f0) }
  .sdata 0x804af238 (NOLOAD) : {
    . = 0x0; cache_804af238 = .;
    . = 0x8; cache_804af240 = .;
    . = 0x10; cache_804af248 = .;
    . = 0x18; cache_804af250 = .;
    . = 0x20; cache_804af258 = .;
    . = 0x28; cache_804af260 = .;
    . = 0x30; cache_804af268 = .;
    . = 0x38; cache_804af270 = .;
    . = 0x40; cache_804af278 = .;
    . = 0x48; cache_804af280 = .;
    . = 0x50; cache_804af288 = .;
    . = 0x58; cache_804af290 = .;
    . = 0x60; cache_804af298 = .;
    . = 0x68; cache_804af2a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

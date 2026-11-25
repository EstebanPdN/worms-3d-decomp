/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_game_clock_init_8011cb5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cached_id_8015f5a0 = 0x8015f5a0;
cast_803426b4 = 0x803426b4;
cast_80342a78 = 0x80342a78;
n_8039afd0 = 0x8039afd0;
n_8039afe4 = 0x8039afe4;
n_8039aff0 = 0x8039aff0;
n_8039affc = 0x8039affc;
n_8039b008 = 0x8039b008;
n_8039b01c = 0x8039b01c;
n_8039b028 = 0x8039b028;
n_8039b03c = 0x8039b03c;
n_8039b050 = 0x8039b050;
n_8039b068 = 0x8039b068;
n_8039b084 = 0x8039b084;
n_8039b09c = 0x8039b09c;
n_8039b0b0 = 0x8039b0b0;
read_setting_800fc1b0 = 0x800fc1b0;
set_value_80178d28 = 0x80178d28;
subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d25i_game_clock_init_8011cb5c 0x8011cb5c : { *(.text.d25i_game_clock_init_8011cb5c) }
  .sdata 0x804af3b8 (NOLOAD) : {
    . = 0x0; cache_804af3b8 = .;
    . = 0x8; cache_804af3c0 = .;
    . = 0x10; cache_804af3c8 = .;
    . = 0x18; cache_804af3d0 = .;
    . = 0x28; cache_804af3e0 = .;
    . = 0x30; cache_804af3e8 = .;
    . = 0x40; cache_804af3f8 = .;
    . = 0x48; cache_804af400 = .;
    . = 0x58; cache_804af410 = .;
    . = 0x68; cache_804af420 = .;
    . = 0x70; cache_804af428 = .;
    . = 0x80; cache_804af438 = .;
    . = 0x88; cache_804af440 = .;
    . = 0x90; cache_804af448 = .;
    . = 0x98; cache_804af450 = .;
    . = 0xa0; cache_804af458 = .;
    . = 0xa8; cache_804af460 = .;
    . = 0xb0; cache_804af468 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

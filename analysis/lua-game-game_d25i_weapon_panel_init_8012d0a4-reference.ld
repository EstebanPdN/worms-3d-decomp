/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_weapon_panel_init_8012d0a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cached_id_8015f5a0 = 0x8015f5a0;
cast_803426b4 = 0x803426b4;
cast_80342a78 = 0x80342a78;
cast_80343744 = 0x80343744;
cast_80343df4 = 0x80343df4;
n_8039d9f4 = 0x8039d9f4;
n_8039da04 = 0x8039da04;
n_8039da14 = 0x8039da14;
n_8039da2c = 0x8039da2c;
n_8039da40 = 0x8039da40;
n_8039da50 = 0x8039da50;
n_8039da64 = 0x8039da64;
n_8039da78 = 0x8039da78;
n_8039da90 = 0x8039da90;
n_8039daa4 = 0x8039daa4;
n_8039dac4 = 0x8039dac4;
read_setting_800fc1b0 = 0x800fc1b0;
set_value_80178d28 = 0x80178d28;
subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d25i_weapon_panel_init_8012d0a4 0x8012d0a4 : { *(.text.d25i_weapon_panel_init_8012d0a4) }
  .sdata 0x804af61c (NOLOAD) : {
    . = 0x0; cache_804af61c = .;
    . = 0x8; cache_804af624 = .;
    . = 0x20; cache_804af63c = .;
    . = 0x28; cache_804af644 = .;
    . = 0x30; cache_804af64c = .;
    . = 0x38; cache_804af654 = .;
    . = 0x50; cache_804af66c = .;
    . = 0x60; cache_804af67c = .;
    . = 0x68; cache_804af684 = .;
    . = 0x80; cache_804af69c = .;
    . = 0x98; cache_804af6b4 = .;
    . = 0xa0; cache_804af6bc = .;
    . = 0xa8; cache_804af6c4 = .;
    . = 0xb0; cache_804af6cc = .;
    . = 0xb8; cache_804af6d4 = .;
    . = 0xc0; cache_804af6dc = .;
    . = 0xc8; cache_804af6e4 = .;
    . = 0xd0; cache_804af6ec = .;
    . = 0xd8; cache_804af6f4 = .;
    . = 0xe0; cache_804af6fc = .;
    . = 0xe8; cache_804af704 = .;
    . = 0xf0; cache_804af70c = .;
    . = 0x108; cache_804af724 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

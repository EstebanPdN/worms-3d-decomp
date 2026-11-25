/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30d_game_update_8015e0e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
elapsed_801fe4d8 = 0x801fe4d8;
name0_803a44d0 = 0x803a44d0;
name1_803a44dc = 0x803a44dc;
name2_803a44e8 = 0x803a44e8;
name3_803a44f0 = 0x803a44f0;
pair_80343994 = 0x80343994;
poll_801fdbec = 0x801fdbec;
reset_801fe314 = 0x801fe314;
service_80344278 = 0x80344278;
stamp_801fc790 = 0x801fc790;
ticks_801fe508 = 0x801fe508;
SECTIONS {
  .text.d30d_game_update_8015e0e0 0x8015e0e0 : { *(.text.d30d_game_update_8015e0e0) }
  .rodata 0x803a4500 : { *(.rodata) }
  .sdata 0x804b0090 (NOLOAD) : {
    . = 0x0; rec0_804b0090 = .;
    . = 0x8; guard0_804b0098 = .;
    . = 0xc; rec1_804b009c = .;
    . = 0x14; guard1_804b00a4 = .;
    . = 0x18; rec2_804b00a8 = .;
    . = 0x20; guard2_804b00b0 = .;
    . = 0x24; rec3_804b00b4 = .;
    . = 0x2c; guard3_804b00bc = .;
    . = 0x17f4; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

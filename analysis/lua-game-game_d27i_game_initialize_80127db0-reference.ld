/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_game_initialize_80127db0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a1_80129108 = 0x80129108;
a2_8015c3ec = 0x8015c3ec;
a3_8015b424 = 0x8015b424;
a4_801fcd6c = 0x801fcd6c;
a5_801fcc48 = 0x801fcc48;
a6_801280b4 = 0x801280b4;
a7_80128f6c = 0x80128f6c;
a8_8015c670 = 0x8015c670;
b1_80127da4 = 0x80127da4;
b2_800fc550 = 0x800fc550;
b3_800e64e8 = 0x800e64e8;
b4_80128bec = 0x80128bec;
b5_801297ec = 0x801297ec;
b6_80129770 = 0x80129770;
c1_801ea57c = 0x801ea57c;
c2_80209b78 = 0x80209b78;
d1_8015aee8 = 0x8015aee8;
d2_80128080 = 0x80128080;
d3_80129340 = 0x80129340;
fa_800fd4c8 = 0x800fd4c8;
fb_800fd504 = 0x800fd504;
rd_800fc1f0 = 0x800fc1f0;
s_8039bea0 = 0x8039bea0;
s_8039bea8 = 0x8039bea8;
s_8039beb8 = 0x8039beb8;
s_8039beec = 0x8039beec;
s_8039bef8 = 0x8039bef8;
s_8039bf30 = 0x8039bf30;
s_8039bf44 = 0x8039bf44;
SECTIONS {
  .text.d27i_game_initialize_80127db0 0x80127db0 : { *(.text.d27i_game_initialize_80127db0) }
  .sdata 0x804ab094 (NOLOAD) : {
    . = 0x0; v_804ab094 = .;
    . = 0x4; v_804ab098 = .;
    . = 0x6758; sys_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

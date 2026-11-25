/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_movie_open_802e04e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_801fdcac = 0x801fdcac;
fn_802098fc = 0x802098fc;
fn_80209920 = 0x80209920;
fn_8020bf2c = 0x8020bf2c;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802e09c4 = 0x802e09c4;
fn_802e10b8 = 0x802e10b8;
fn_802e1134 = 0x802e1134;
fn_802e22c0 = 0x802e22c0;
fn_802ebfbc = 0x802ebfbc;
fn_802f5258 = 0x802f5258;
fn_802f5320 = 0x802f5320;
fn_802fb7ac = 0x802fb7ac;
fn_802fb82c = 0x802fb82c;
fn_80304c00 = 0x80304c00;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343994 = 0x80343994;
memset = 0x802eefe0;
s_803db090 = 0x803db090;
s_803db10c = 0x803db10c;
s_803db144 = 0x803db144;
s_803db14c = 0x803db14c;
s_803db15c = 0x803db15c;
s_803db184 = 0x803db184;
s_803db188 = 0x803db188;
s_803db1a0 = 0x803db1a0;
s_803db1bc = 0x803db1bc;
s_803db1f8 = 0x803db1f8;
s_803db208 = 0x803db208;
strcmp = 0x802ef234;
SECTIONS {
  .text.d27l_movie_open_802e04e0 0x802e04e0 : { *(.text.d27l_movie_open_802e04e0) }
  .rodata 0x803db224 : { *(.rodata) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; heap_804ab8b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

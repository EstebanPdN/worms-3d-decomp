/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f7a_team_message_80296de0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__9F7aString = 0x803426b8;
__9F7aStringPCc = 0x8020bb54;
fn_800a830c = 0x800a830c;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc550 = 0x800fc550;
fn_8010a8fc = 0x8010a8fc;
fn_8015f65c = 0x8015f65c;
fn_8016293c = 0x8016293c;
fn_8020bd38 = 0x8020bd38;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802972f0 = 0x802972f0;
fn_802975f8 = 0x802975f8;
fn_80297620 = 0x80297620;
fn_802979b8 = 0x802979b8;
fn_80297f7c = 0x80297f7c;
fn_80298abc = 0x80298abc;
fn_80298dd4 = 0x80298dd4;
fn_80298e84 = 0x80298e84;
fn_802991b0 = 0x802991b0;
fn_80299520 = 0x80299520;
fn_80299630 = 0x80299630;
fn_80299a74 = 0x80299a74;
fn_80299ca4 = 0x80299ca4;
fn_80299fc4 = 0x80299fc4;
fn_8029a238 = 0x8029a238;
fn_8029b410 = 0x8029b410;
fn_8029b4dc = 0x8029b4dc;
fn_8029b73c = 0x8029b73c;
fn_8029b83c = 0x8029b83c;
fn_8029c4d0 = 0x8029c4d0;
fn_8029cdb4 = 0x8029cdb4;
fn_8029d0ec = 0x8029d0ec;
fn_8029d410 = 0x8029d410;
fn_802ed89c = 0x802ed89c;
fn_802ef234 = 0x802ef234;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
new_803d093c = 0x803d093c;
selected_803d092c = 0x803d092c;
SECTIONS {
  .text.w3d_f7a_team_message_80296de0 0x80296de0 : { *(.text.w3d_f7a_team_message_80296de0) }
  .sdata 0x804b0d9c (NOLOAD) : {
    . = 0x0; cache_804b0d9c = .;
    . = 0x8; cache_804b0da4 = .;
    . = 0x10; cache_804b0dac = .;
    . = 0x18; cache_804b0db4 = .;
    . = 0x20; cache_804b0dbc = .;
    . = 0x28; cache_804b0dc4 = .;
    . = 0x30; cache_804b0dcc = .;
    . = 0x38; cache_804b0dd4 = .;
    . = 0x40; cache_804b0ddc = .;
    . = 0x48; cache_804b0de4 = .;
    . = 0x50; cache_804b0dec = .;
    . = 0x58; cache_804b0df4 = .;
    . = 0x60; cache_804b0dfc = .;
    . = 0x68; cache_804b0e04 = .;
    . = 0x70; cache_804b0e0c = .;
    . = 0x78; cache_804b0e14 = .;
    . = 0x80; cache_804b0e1c = .;
    . = 0x88; cache_804b0e24 = .;
    . = 0x90; cache_804b0e2c = .;
    . = 0x98; cache_804b0e34 = .;
    . = 0xa0; cache_804b0e3c = .;
    . = 0xa8; cache_804b0e44 = .;
    . = 0xb0; cache_804b0e4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

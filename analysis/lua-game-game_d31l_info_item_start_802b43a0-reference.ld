/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31l_info_item_start_802b43a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_800fc1b0 = 0x800fc1b0;
fn_800fd62c = 0x800fd62c;
fn_8015adf4 = 0x8015adf4;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_80173df0 = 0x80173df0;
fn_8020bd38 = 0x8020bd38;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b0b84 = 0x802b0b84;
fn_802b1510 = 0x802b1510;
fn_802b49b0 = 0x802b49b0;
fn_802b4e8c = 0x802b4e8c;
fn_802b4ef4 = 0x802b4ef4;
fn_802b5050 = 0x802b5050;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_8034357c = 0x8034357c;
str_803d7d60 = 0x803d7d60;
str_803d7d84 = 0x803d7d84;
str_803d7d90 = 0x803d7d90;
str_803d7d9c = 0x803d7d9c;
str_803d7df0 = 0x803d7df0;
SECTIONS {
  .text.d31l_info_item_start_802b43a0 0x802b43a0 : { *(.text.d31l_info_item_start_802b43a0) }
  .sdata 0x804b1008 (NOLOAD) : {
    . = 0x0; msg_804b1008 = .;
    . = 0x8; msg_804b1010 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8004def0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002AA48 = 0x8002aa48;
fn_8002AE70 = 0x8002ae70;
fn_8004E324 = 0x8004e324;
fn_800621C8 = 0x800621c8;
fn_80062228 = 0x80062228;
fn_80062390 = 0x80062390;
fn_800627A4 = 0x800627a4;
fn_80062884 = 0x80062884;
fn_8006E71C = 0x8006e71c;
fn_800FC1B0 = 0x800fc1b0;
fn_800FC5DC = 0x800fc5dc;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_80162024 = 0x80162024;
fn_8016239C = 0x8016239c;
fn_8020C5C4 = 0x8020c5c4;
fn_802CC4F0 = 0x802cc4f0;
fn_802EF234 = 0x802ef234;
fn_80341588 = 0x80341588;
lbl_80377788 = 0x80377788;
lbl_8037779C = 0x8037779c;
lbl_803778B4 = 0x803778b4;
lbl_80377F30 = 0x80377f30;
lbl_80378194 = 0x80378194;
lbl_803791B0 = 0x803791b0;
lbl_803791C0 = 0x803791c0;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_8004def0 0x8004def0 : { *(.text.w3d_auto_8004def0) }
  .text.w3d_auto_8004ef24 0x8004ef24 : { *(.text.w3d_auto_8004ef24) }
  .text.w3d_auto_8004fd6c 0x8004fd6c : { *(.text.w3d_auto_8004fd6c) }
  .text.w3d_auto_80051a18 0x80051a18 : { *(.text.w3d_auto_80051a18) }
  .text.w3d_auto_800608d4 0x800608d4 : { *(.text.w3d_auto_800608d4) }
  .text.w3d_auto_80062074 0x80062074 : { *(.text.w3d_auto_80062074) }
  .text.w3d_auto_80062160 0x80062160 : { *(.text.w3d_auto_80062160) }
  .sdata 0x804ad424 (NOLOAD) : {
    . = 0x0; lbl_804AD424 = .;
    . = 0x18; lbl_804AD43C = .;
    . = 0x20; lbl_804AD444 = .;
    . = 0x3c; lbl_804AD460 = .;
    . = 0xec; lbl_804AD510 = .;
    . = 0xf4; lbl_804AD518 = .;
    . = 0x4330; lbl_804B1754 = .;
    . = 0x43c0; lbl_804B17E4 = .;
    . = 0x43c4; lbl_804B17E8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

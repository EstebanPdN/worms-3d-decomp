/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800e4f38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
fn_8003F240 = 0x8003f240;
fn_800DC634 = 0x800dc634;
fn_800E67D0 = 0x800e67d0;
fn_800EB910 = 0x800eb910;
fn_800FC1B0 = 0x800fc1b0;
fn_80126334 = 0x80126334;
fn_801264FC = 0x801264fc;
fn_80126524 = 0x80126524;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_80162024 = 0x80162024;
fn_8016239C = 0x8016239c;
fn_801628B0 = 0x801628b0;
fn_80178D1C = 0x80178d1c;
fn_801797B4 = 0x801797b4;
fn_802EE7DC = 0x802ee7dc;
fn_80341584 = 0x80341584;
lbl_8038A1BC = 0x8038a1bc;
lbl_8038A5CC = 0x8038a5cc;
lbl_8038A5DC = 0x8038a5dc;
lbl_8038A5F4 = 0x8038a5f4;
lbl_8038A604 = 0x8038a604;
lbl_8038A614 = 0x8038a614;
lbl_8038A620 = 0x8038a620;
lbl_8038B148 = 0x8038b148;
lbl_8038B150 = 0x8038b150;
lbl_8038B154 = 0x8038b154;
lbl_8038B168 = 0x8038b168;
lbl_8038B17C = 0x8038b17c;
lbl_8038B190 = 0x8038b190;
lbl_8038B3F4 = 0x8038b3f4;
lbl_8040DB38 = 0x8040db38;
lbl_804100B8 = 0x804100b8;
lbl_804100E8 = 0x804100e8;
SECTIONS {
  .text.w3d_auto_800e4f38 0x800e4f38 : { *(.text.w3d_auto_800e4f38) }
  .text.w3d_auto_800e50cc 0x800e50cc : { *(.text.w3d_auto_800e50cc) }
  .text.w3d_auto_800e6390 0x800e6390 : { *(.text.w3d_auto_800e6390) }
  .text.w3d_auto_800e6738 0x800e6738 : { *(.text.w3d_auto_800e6738) }
  .text.w3d_auto_800e783c 0x800e783c : { *(.text.w3d_auto_800e783c) }
  .text.w3d_auto_800e78d4 0x800e78d4 : { *(.text.w3d_auto_800e78d4) }
  .text.w3d_auto_800eabb0 0x800eabb0 : { *(.text.w3d_auto_800eabb0) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x96; lbl_804AA95E = .;
    . = 0x604; lbl_804AAECC = .;
    . = 0x44b4; lbl_804AED7C = .;
    . = 0x44ec; lbl_804AEDB4 = .;
    . = 0x44f4; lbl_804AEDBC = .;
    . = 0x44fc; lbl_804AEDC4 = .;
    . = 0x4514; lbl_804AEDDC = .;
    . = 0x451c; lbl_804AEDE4 = .;
    . = 0x4564; lbl_804AEE2C = .;
    . = 0x456c; lbl_804AEE34 = .;
    . = 0x4574; lbl_804AEE3C = .;
    . = 0x457c; lbl_804AEE44 = .;
    . = 0x6e8c; lbl_804B1754 = .;
    . = 0x6ec0; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

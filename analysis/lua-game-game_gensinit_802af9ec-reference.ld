/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_802af9ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
fn_802af2e0 = 0x802af2e0;
fn_802b5450 = 0x802b5450;
fn_802c1ec4 = 0x802c1ec4;
lbl_803617d0 = 0x803617d0;
lbl_80368a58 = 0x80368a58;
lbl_80368ae8 = 0x80368ae8;
lbl_80368ba8 = 0x80368ba8;
lbl_803d78a8 = 0x803d78a8;
lbl_803d78bc = 0x803d78bc;
lbl_803d78d8 = 0x803d78d8;
lbl_803d78ec = 0x803d78ec;
lbl_803d7908 = 0x803d7908;
lbl_803d7918 = 0x803d7918;
lbl_803d792c = 0x803d792c;
lbl_803d793c = 0x803d793c;
lbl_803d794c = 0x803d794c;
lbl_803d7964 = 0x803d7964;
lbl_803d8120 = 0x803d8120;
lbl_803d8134 = 0x803d8134;
lbl_803d8144 = 0x803d8144;
lbl_803d8154 = 0x803d8154;
lbl_803d8168 = 0x803d8168;
lbl_803d817c = 0x803d817c;
lbl_803d818c = 0x803d818c;
lbl_803d81a0 = 0x803d81a0;
lbl_803d81b8 = 0x803d81b8;
lbl_803d81c8 = 0x803d81c8;
lbl_803d881c = 0x803d881c;
lbl_803d882c = 0x803d882c;
lbl_803d8840 = 0x803d8840;
lbl_803d8850 = 0x803d8850;
lbl_803d8860 = 0x803d8860;
lbl_803d8874 = 0x803d8874;
lbl_803eb4c4 = 0x803eb4c4;
lbl_803eb518 = 0x803eb518;
lbl_803eb588 = 0x803eb588;
SECTIONS {
  .text.w3d_sinit_802af9ec 0x802af9ec : { *(.text.w3d_sinit_802af9ec) }
  .text.w3d_sinit_802ba1a4 0x802ba1a4 : { *(.text.w3d_sinit_802ba1a4) }
  .text.w3d_sinit_802c4f30 0x802c4f30 : { *(.text.w3d_sinit_802c4f30) }
  .sdata 0x804b0f2c (NOLOAD) : {
    . = 0x0; lbl_804b0f2c = .;
    . = 0x8; lbl_804b0f34 = .;
    . = 0x10; lbl_804b0f3c = .;
    . = 0x18; lbl_804b0f44 = .;
    . = 0x20; lbl_804b0f4c = .;
    . = 0x28; lbl_804b0f54 = .;
    . = 0x30; lbl_804b0f5c = .;
    . = 0x38; lbl_804b0f64 = .;
    . = 0x40; lbl_804b0f6c = .;
    . = 0x48; lbl_804b0f74 = .;
    . = 0xec; lbl_804b1018 = .;
    . = 0xf4; lbl_804b1020 = .;
    . = 0xfc; lbl_804b1028 = .;
    . = 0x104; lbl_804b1030 = .;
    . = 0x10c; lbl_804b1038 = .;
    . = 0x114; lbl_804b1040 = .;
    . = 0x11c; lbl_804b1048 = .;
    . = 0x124; lbl_804b1050 = .;
    . = 0x12c; lbl_804b1058 = .;
    . = 0x134; lbl_804b1060 = .;
    . = 0x144; lbl_804b1070 = .;
    . = 0x14c; lbl_804b1078 = .;
    . = 0x154; lbl_804b1080 = .;
    . = 0x15c; lbl_804b1088 = .;
    . = 0x164; lbl_804b1090 = .;
    . = 0x16c; lbl_804b1098 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

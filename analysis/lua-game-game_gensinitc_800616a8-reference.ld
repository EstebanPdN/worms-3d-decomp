/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_800616a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_80160038PvN21ii = 0x80160038;
__16W3dType_8016115cPvN21ii = 0x8016115c;
__16W3dType_801629f8PvN21ii = 0x801629f8;
__16W3dType_8020fbd0PvN21ii = 0x8020fbd0;
fn_80061310 = 0x80061310;
fn_80070014 = 0x80070014;
fn_8010e5c4 = 0x8010e5c4;
fn_8012a864 = 0x8012a864;
fn_8015f518 = 0x8015f518;
fn_80166c64 = 0x80166c64;
fn_80190680 = 0x80190680;
fn_8019d954 = 0x8019d954;
fn_801f9738 = 0x801f9738;
fn_801f97e8 = 0x801f97e8;
fn_801fc090 = 0x801fc090;
fn_801fc140 = 0x801fc140;
fn_802097ec = 0x802097ec;
fn_8020fbd0 = 0x8020fbd0;
fn_802c0dd8 = 0x802c0dd8;
lbl_80360240 = 0x80360240;
lbl_80360450 = 0x80360450;
lbl_80360de0 = 0x80360de0;
lbl_80360e10 = 0x80360e10;
lbl_80361230 = 0x80361230;
lbl_803614a0 = 0x803614a0;
lbl_803617d0 = 0x803617d0;
lbl_803618f0 = 0x803618f0;
lbl_803619fc = 0x803619fc;
lbl_80361f88 = 0x80361f88;
lbl_80362270 = 0x80362270;
lbl_80365838 = 0x80365838;
lbl_80365868 = 0x80365868;
lbl_80365898 = 0x80365898;
lbl_803658c8 = 0x803658c8;
lbl_80368b78 = 0x80368b78;
lbl_803792cc = 0x803792cc;
lbl_8037ca08 = 0x8037ca08;
lbl_8039a99c = 0x8039a99c;
lbl_8039d2c4 = 0x8039d2c4;
lbl_803a4f98 = 0x803a4f98;
lbl_803a8264 = 0x803a8264;
lbl_803a9940 = 0x803a9940;
lbl_803d8540 = 0x803d8540;
lbl_803e7b58 = 0x803e7b58;
lbl_803e7c8c = 0x803e7c8c;
lbl_803e84a4 = 0x803e84a4;
lbl_803e8610 = 0x803e8610;
lbl_803e893c = 0x803e893c;
lbl_803e8bdc = 0x803e8bdc;
lbl_803e8d10 = 0x803e8d10;
lbl_803ea130 = 0x803ea130;
lbl_803ea14c = 0x803ea14c;
lbl_803ea168 = 0x803ea168;
lbl_803ea184 = 0x803ea184;
lbl_803eb56c = 0x803eb56c;
SECTIONS {
  .text.w3d_sinit_800616a8 0x800616a8 : { *(.text.w3d_sinit_800616a8) }
  .text.w3d_sinit_80070780 0x80070780 : { *(.text.w3d_sinit_80070780) }
  .text.w3d_sinit_80118120 0x80118120 : { *(.text.w3d_sinit_80118120) }
  .text.w3d_sinit_8012b000 0x8012b000 : { *(.text.w3d_sinit_8012b000) }
  .text.w3d_sinit_801686a4 0x801686a4 : { *(.text.w3d_sinit_801686a4) }
  .text.w3d_sinit_8019401c 0x8019401c : { *(.text.w3d_sinit_8019401c) }
  .text.w3d_sinit_8019e398 0x8019e398 : { *(.text.w3d_sinit_8019e398) }
  .text.w3d_sinit_801fbeac 0x801fbeac : { *(.text.w3d_sinit_801fbeac) }
  .text.w3d_sinit_801fc6d0 0x801fc6d0 : { *(.text.w3d_sinit_801fc6d0) }
  .text.w3d_sinit_802c1dd8 0x802c1dd8 : { *(.text.w3d_sinit_802c1dd8) }
  .sdata 0x804ad4e0 (NOLOAD) : {
    . = 0x0; lbl_804ad4e0 = .;
    . = 0x3b4; lbl_804ad894 = .;
    . = 0x1e28; lbl_804af308 = .;
    . = 0x2128; lbl_804af608 = .;
    . = 0x2bfc; lbl_804b00dc = .;
    . = 0x2dd4; lbl_804b02b4 = .;
    . = 0x2e3c; lbl_804b031c = .;
    . = 0x3b88; lbl_804b1068 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

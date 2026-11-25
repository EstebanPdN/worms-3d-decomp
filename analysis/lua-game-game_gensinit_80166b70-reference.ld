/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_80166b70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016656c = 0x8016656c;
fn_80169a88 = 0x80169a88;
fn_801a51ac = 0x801a51ac;
fn_801a6038 = 0x801a6038;
fn_801a8010 = 0x801a8010;
fn_801ab0e0 = 0x801ab0e0;
fn_801ac014 = 0x801ac014;
fn_801d2fc8 = 0x801d2fc8;
fn_801d52c4 = 0x801d52c4;
fn_801d5c38 = 0x801d5c38;
fn_801d98ec = 0x801d98ec;
fn_801e7174 = 0x801e7174;
fn_801e74d0 = 0x801e74d0;
fn_801fc86c = 0x801fc86c;
fn_8020fbd0 = 0x8020fbd0;
fn_802e2eac = 0x802e2eac;
lbl_803619b0 = 0x803619b0;
lbl_80361a2c = 0x80361a2c;
lbl_80362360 = 0x80362360;
lbl_803623ac = 0x803623ac;
lbl_80362444 = 0x80362444;
lbl_80362490 = 0x80362490;
lbl_803624dc = 0x803624dc;
lbl_80365394 = 0x80365394;
lbl_803654a8 = 0x803654a8;
lbl_803654f4 = 0x803654f4;
lbl_80365540 = 0x80365540;
lbl_8036573c = 0x8036573c;
lbl_80368c68 = 0x80368c68;
lbl_803e8920 = 0x803e8920;
lbl_803e8958 = 0x803e8958;
lbl_803e8d9c = 0x803e8d9c;
lbl_803e8db8 = 0x803e8db8;
lbl_803e8df0 = 0x803e8df0;
lbl_803e8e0c = 0x803e8e0c;
lbl_803e8e28 = 0x803e8e28;
lbl_803e9ec8 = 0x803e9ec8;
lbl_803e9f38 = 0x803e9f38;
lbl_803e9f54 = 0x803e9f54;
lbl_803e9f70 = 0x803e9f70;
lbl_803eb5f8 = 0x803eb5f8;
lbl_803fe28c = 0x803fe28c;
lbl_803fe350 = 0x803fe350;
lbl_803fe9ac = 0x803fe9ac;
lbl_803fe9cc = 0x803fe9cc;
lbl_803fe9ec = 0x803fe9ec;
lbl_803fea2c = 0x803fea2c;
lbl_803fea4c = 0x803fea4c;
lbl_803fea6c = 0x803fea6c;
lbl_803ff134 = 0x803ff134;
lbl_803ff194 = 0x803ff194;
lbl_803ff1b4 = 0x803ff1b4;
lbl_803ffe14 = 0x803ffe14;
SECTIONS {
  .text.w3d_sinit_80166b70 0x80166b70 : { *(.text.w3d_sinit_80166b70) }
  .text.w3d_sinit_8016a278 0x8016a278 : { *(.text.w3d_sinit_8016a278) }
  .text.w3d_sinit_801a4cf4 0x801a4cf4 : { *(.text.w3d_sinit_801a4cf4) }
  .text.w3d_sinit_801a5f44 0x801a5f44 : { *(.text.w3d_sinit_801a5f44) }
  .text.w3d_sinit_801a6ff8 0x801a6ff8 : { *(.text.w3d_sinit_801a6ff8) }
  .text.w3d_sinit_801aafb8 0x801aafb8 : { *(.text.w3d_sinit_801aafb8) }
  .text.w3d_sinit_801abf20 0x801abf20 : { *(.text.w3d_sinit_801abf20) }
  .text.w3d_sinit_801ac520 0x801ac520 : { *(.text.w3d_sinit_801ac520) }
  .text.w3d_sinit_801d3fd0 0x801d3fd0 : { *(.text.w3d_sinit_801d3fd0) }
  .text.w3d_sinit_801d5b44 0x801d5b44 : { *(.text.w3d_sinit_801d5b44) }
  .text.w3d_sinit_801d6740 0x801d6740 : { *(.text.w3d_sinit_801d6740) }
  .text.w3d_sinit_801d9e68 0x801d9e68 : { *(.text.w3d_sinit_801d9e68) }
  .text.w3d_sinit_802e3088 0x802e3088 : { *(.text.w3d_sinit_802e3088) }
  .sdata 0x804b00d4 (NOLOAD) : {
    . = 0x0; lbl_804b00d4 = .;
    . = 0x18; lbl_804b00ec = .;
    . = 0x254; lbl_804b0328 = .;
    . = 0x258; lbl_804b032c = .;
    . = 0x25c; lbl_804b0330 = .;
    . = 0x268; lbl_804b033c = .;
    . = 0x26c; lbl_804b0340 = .;
    . = 0x270; lbl_804b0344 = .;
    . = 0x468; lbl_804b053c = .;
    . = 0x474; lbl_804b0548 = .;
    . = 0x478; lbl_804b054c = .;
    . = 0x488; lbl_804b055c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80015eb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80015D18 = 0x80015d18;
fn_80035714 = 0x80035714;
fn_800A5E04 = 0x800a5e04;
fn_800A7E14 = 0x800a7e14;
fn_800C56B8 = 0x800c56b8;
fn_800E5BB8 = 0x800e5bb8;
fn_800E9DC8 = 0x800e9dc8;
fn_800FC230 = 0x800fc230;
fn_800FC4C8 = 0x800fc4c8;
fn_80126230 = 0x80126230;
fn_801265A4 = 0x801265a4;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_80162024 = 0x80162024;
fn_8016239C = 0x8016239c;
fn_80164CEC = 0x80164cec;
fn_801797B4 = 0x801797b4;
fn_801FE240 = 0x801fe240;
fn_80209920 = 0x80209920;
fn_802134FC = 0x802134fc;
fn_8026DA58 = 0x8026da58;
fn_80341584 = 0x80341584;
fn_80342730 = 0x80342730;
lbl_80372474 = 0x80372474;
lbl_80372488 = 0x80372488;
lbl_8037249C = 0x8037249c;
lbl_803724BC = 0x803724bc;
lbl_803724C0 = 0x803724c0;
lbl_8037EB3C = 0x8037eb3c;
lbl_8037EB44 = 0x8037eb44;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_80015eb0 0x80015eb0 : { *(.text.w3d_auto_80015eb0) }
  .text.w3d_auto_8002aba4 0x8002aba4 : { *(.text.w3d_auto_8002aba4) }
  .text.w3d_auto_8002acd0 0x8002acd0 : { *(.text.w3d_auto_8002acd0) }
  .text.w3d_auto_8002c490 0x8002c490 : { *(.text.w3d_auto_8002c490) }
  .text.w3d_auto_80069430 0x80069430 : { *(.text.w3d_auto_80069430) }
  .text.w3d_auto_8006ac40 0x8006ac40 : { *(.text.w3d_auto_8006ac40) }
  .text.w3d_auto_800953e8 0x800953e8 : { *(.text.w3d_auto_800953e8) }
  .text.w3d_auto_800a4da4 0x800a4da4 : { *(.text.w3d_auto_800a4da4) }
  .text.w3d_auto_800a5db0 0x800a5db0 : { *(.text.w3d_auto_800a5db0) }
  .text.w3d_auto_800d5678 0x800d5678 : { *(.text.w3d_auto_800d5678) }
  .text.w3d_auto_800d82cc 0x800d82cc : { *(.text.w3d_auto_800d82cc) }
  .text.w3d_auto_800e88e0 0x800e88e0 : { *(.text.w3d_auto_800e88e0) }
  .sdata 0x804aa6f4 (NOLOAD) : {
    . = 0x0; lbl_804AA6F4 = .;
    . = 0x4; lbl_804AA6F8 = .;
    . = 0x1d4; lbl_804AA8C8 = .;
    . = 0x3a8; lbl_804AAA9C = .;
    . = 0x1488; lbl_804ABB7C = .;
    . = 0x2540; lbl_804ACC34 = .;
    . = 0x2558; lbl_804ACC4C = .;
    . = 0x2568; lbl_804ACC5C = .;
    . = 0x2578; lbl_804ACC6C = .;
    . = 0x3b8c; lbl_804AE280 = .;
    . = 0x4ec8; lbl_804AF5BC = .;
    . = 0x7060; lbl_804B1754 = .;
    . = 0x7098; lbl_804B178C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

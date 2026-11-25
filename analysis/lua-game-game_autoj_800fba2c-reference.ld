/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800fba2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80069A0C = 0x80069a0c;
fn_80069A30 = 0x80069a30;
fn_800A82F0 = 0x800a82f0;
fn_800A8314 = 0x800a8314;
fn_8010A8E0 = 0x8010a8e0;
fn_801613F0 = 0x801613f0;
fn_80178C48 = 0x80178c48;
fn_80178C54 = 0x80178c54;
fn_8019FE48 = 0x8019fe48;
fn_801EA704 = 0x801ea704;
fn_801F9DF8 = 0x801f9df8;
fn_801F9F2C = 0x801f9f2c;
fn_801FAC4C = 0x801fac4c;
fn_802098D8 = 0x802098d8;
fn_80209920 = 0x80209920;
fn_802CE30C = 0x802ce30c;
fn_803426B4 = 0x803426b4;
SECTIONS {
  .text.w3d_auto_800fba2c 0x800fba2c : { *(.text.w3d_auto_800fba2c) }
  .text.w3d_auto_800fba6c 0x800fba6c : { *(.text.w3d_auto_800fba6c) }
  .text.w3d_auto_800fbab0 0x800fbab0 : { *(.text.w3d_auto_800fbab0) }
  .text.w3d_auto_800fbaf0 0x800fbaf0 : { *(.text.w3d_auto_800fbaf0) }
  .text.w3d_auto_800fbb30 0x800fbb30 : { *(.text.w3d_auto_800fbb30) }
  .text.w3d_auto_8019fdd8 0x8019fdd8 : { *(.text.w3d_auto_8019fdd8) }
  .text.w3d_auto_8019fe10 0x8019fe10 : { *(.text.w3d_auto_8019fe10) }
  .text.w3d_auto_801ea70c 0x801ea70c : { *(.text.w3d_auto_801ea70c) }
  .text.w3d_auto_801ea740 0x801ea740 : { *(.text.w3d_auto_801ea740) }
  .text.w3d_auto_801fa654 0x801fa654 : { *(.text.w3d_auto_801fa654) }
  .text.w3d_auto_801fa688 0x801fa688 : { *(.text.w3d_auto_801fa688) }
  .text.w3d_auto_802aff04 0x802aff04 : { *(.text.w3d_auto_802aff04) }
  .text.w3d_auto_802aff50 0x802aff50 : { *(.text.w3d_auto_802aff50) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80020880)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80022634 = 0x80022634;
fn_800271EC = 0x800271ec;
fn_8002726C = 0x8002726c;
fn_8015F5A0 = 0x8015f5a0;
fn_8015FEF0 = 0x8015fef0;
fn_80162024 = 0x80162024;
fn_801628B0 = 0x801628b0;
fn_80165254 = 0x80165254;
fn_801FFECC = 0x801ffecc;
fn_8020BD38 = 0x8020bd38;
fn_802E0210 = 0x802e0210;
fn_803426B8 = 0x803426b8;
lbl_80387410 = 0x80387410;
lbl_8040E6D8 = 0x8040e6d8;
lbl_8040FE00 = 0x8040fe00;
lbl_80418D88 = 0x80418d88;
lbl_80419CB0 = 0x80419cb0;
SECTIONS {
  .text.w3d_auto_80020880 0x80020880 : { *(.text.w3d_auto_80020880) }
  .text.w3d_auto_800231ec 0x800231ec : { *(.text.w3d_auto_800231ec) }
  .text.w3d_auto_8002709c 0x8002709c : { *(.text.w3d_auto_8002709c) }
  .text.w3d_auto_8003a490 0x8003a490 : { *(.text.w3d_auto_8003a490) }
  .text.w3d_auto_800b912c 0x800b912c : { *(.text.w3d_auto_800b912c) }
  .text.w3d_auto_800c6a20 0x800c6a20 : { *(.text.w3d_auto_800c6a20) }
  .text.w3d_auto_800da250 0x800da250 : { *(.text.w3d_auto_800da250) }
  .text.w3d_auto_801626ec 0x801626ec : { *(.text.w3d_auto_801626ec) }
  .text.w3d_auto_80178870 0x80178870 : { *(.text.w3d_auto_80178870) }
  .text.w3d_auto_801797ec 0x801797ec : { *(.text.w3d_auto_801797ec) }
  .text.w3d_auto_801d5f60 0x801d5f60 : { *(.text.w3d_auto_801d5f60) }
  .text.w3d_auto_80200340 0x80200340 : { *(.text.w3d_auto_80200340) }
  .text.w3d_auto_8021cbc8 0x8021cbc8 : { *(.text.w3d_auto_8021cbc8) }
  .text.w3d_auto_8034f190 0x8034f190 : { *(.text.w3d_auto_8034f190) }
  .text.w3d_auto_8035a230 0x8035a230 : { *(.text.w3d_auto_8035a230) }
  .sdata 0x804aa7a8 (NOLOAD) : {
    . = 0x0; lbl_804AA7A8 = .;
    . = 0x664; lbl_804AAE0C = .;
    . = 0x3fec; lbl_804AE794 = .;
    . = 0x3ff4; lbl_804AE79C = .;
    . = 0x3ffc; lbl_804AE7A4 = .;
    . = 0x4004; lbl_804AE7AC = .;
    . = 0x400c; lbl_804AE7B4 = .;
    . = 0x4024; lbl_804AE7CC = .;
    . = 0x4044; lbl_804AE7EC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

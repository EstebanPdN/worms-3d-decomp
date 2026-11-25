/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800aa374)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800520F4 = 0x800520f4;
fn_800AAF5C = 0x800aaf5c;
fn_800AB944 = 0x800ab944;
fn_800ABA08 = 0x800aba08;
fn_800AC0F4 = 0x800ac0f4;
fn_800AC11C = 0x800ac11c;
fn_800AC278 = 0x800ac278;
fn_800C6F20 = 0x800c6f20;
fn_800FDE64 = 0x800fde64;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8015FD1C = 0x8015fd1c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80165254 = 0x80165254;
fn_80178DF0 = 0x80178df0;
fn_8020C5C4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
lbl_80381C40 = 0x80381c40;
lbl_80382070 = 0x80382070;
lbl_80382084 = 0x80382084;
lbl_80382278 = 0x80382278;
lbl_8038228C = 0x8038228c;
lbl_803826A0 = 0x803826a0;
lbl_80383008 = 0x80383008;
lbl_8040DB38 = 0x8040db38;
lbl_8040F728 = 0x8040f728;
lbl_8043E464 = 0x8043e464;
SECTIONS {
  .text.w3d_auto_800aa374 0x800aa374 : { *(.text.w3d_auto_800aa374) }
  .text.w3d_auto_800aba08 0x800aba08 : { *(.text.w3d_auto_800aba08) }
  .text.w3d_auto_800abfe0 0x800abfe0 : { *(.text.w3d_auto_800abfe0) }
  .text.w3d_auto_800ad8b4 0x800ad8b4 : { *(.text.w3d_auto_800ad8b4) }
  .text.w3d_auto_800af1e0 0x800af1e0 : { *(.text.w3d_auto_800af1e0) }
  .text.w3d_auto_800af2b0 0x800af2b0 : { *(.text.w3d_auto_800af2b0) }
  .text.w3d_auto_800b931c 0x800b931c : { *(.text.w3d_auto_800b931c) }
  .text.w3d_auto_800bc350 0x800bc350 : { *(.text.w3d_auto_800bc350) }
  .text.w3d_auto_800bc390 0x800bc390 : { *(.text.w3d_auto_800bc390) }
  .text.w3d_auto_800c1674 0x800c1674 : { *(.text.w3d_auto_800c1674) }
  .text.w3d_auto_800c6cf4 0x800c6cf4 : { *(.text.w3d_auto_800c6cf4) }
  .sdata 0x804ae330 (NOLOAD) : {
    . = 0x0; lbl_804AE330 = .;
    . = 0x8; lbl_804AE338 = .;
    . = 0x10; lbl_804AE340 = .;
    . = 0x18; lbl_804AE348 = .;
    . = 0x20; lbl_804AE350 = .;
    . = 0x28; lbl_804AE358 = .;
    . = 0x30; lbl_804AE360 = .;
    . = 0x38; lbl_804AE368 = .;
    . = 0x40; lbl_804AE370 = .;
    . = 0x48; lbl_804AE378 = .;
    . = 0x70; lbl_804AE3A0 = .;
    . = 0x98; lbl_804AE3C8 = .;
    . = 0xa0; lbl_804AE3D0 = .;
    . = 0xbc; lbl_804AE3EC = .;
    . = 0xc4; lbl_804AE3F4 = .;
    . = 0x1e0; lbl_804AE510 = .;
    . = 0x348; lbl_804AE678 = .;
    . = 0x3424; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

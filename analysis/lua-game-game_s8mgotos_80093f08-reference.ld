/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_recovered_80093f08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002AA48 = 0x8002aa48;
fn_8002AD9C = 0x8002ad9c;
fn_8002AE70 = 0x8002ae70;
fn_80035714 = 0x80035714;
fn_80094E08 = 0x80094e08;
fn_800953E8 = 0x800953e8;
fn_80095648 = 0x80095648;
fn_800A7E14 = 0x800a7e14;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_8037EA14 = 0x8037ea14;
lbl_8037EA24 = 0x8037ea24;
lbl_8037EA30 = 0x8037ea30;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s8_recovered_80093f08 0x80093f08 : { *(.text.s8_recovered_80093f08) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x3588; lbl_804ADE50 = .;
    . = 0x3590; lbl_804ADE58 = .;
    . = 0x3598; lbl_804ADE60 = .;
    . = 0x35a0; lbl_804ADE68 = .;
    . = 0x35a8; lbl_804ADE70 = .;
    . = 0x35b0; lbl_804ADE78 = .;
    . = 0x35b8; lbl_804ADE80 = .;
    . = 0x35c0; lbl_804ADE88 = .;
    . = 0x35c8; lbl_804ADE90 = .;
    . = 0x35d0; lbl_804ADE98 = .;
    . = 0x35d8; lbl_804ADEA0 = .;
    . = 0x35e0; lbl_804ADEA8 = .;
    . = 0x35e8; lbl_804ADEB0 = .;
    . = 0x35f0; lbl_804ADEB8 = .;
    . = 0x35f8; lbl_804ADEC0 = .;
    . = 0x3600; lbl_804ADEC8 = .;
    . = 0x3608; lbl_804ADED0 = .;
    . = 0x3610; lbl_804ADED8 = .;
    . = 0x3618; lbl_804ADEE0 = .;
    . = 0x3620; lbl_804ADEE8 = .;
    . = 0x3628; lbl_804ADEF0 = .;
    . = 0x3630; lbl_804ADEF8 = .;
    . = 0x3638; lbl_804ADF00 = .;
    . = 0x3648; lbl_804ADF10 = .;
    . = 0x3668; lbl_804ADF30 = .;
    . = 0x3670; lbl_804ADF38 = .;
    . = 0x3678; lbl_804ADF40 = .;
    . = 0x6e8c; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

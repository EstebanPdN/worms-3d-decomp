/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_activate_and_post_800ac278)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800AC0F4 = 0x800ac0f4;
fn_800AC14C = 0x800ac14c;
fn_800FDD80 = 0x800fdd80;
fn_8011AFAC = 0x8011afac;
fn_80125FDC = 0x80125fdc;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80165254 = 0x80165254;
lbl_8040DB38 = 0x8040db38;
lbl_8045E788 = 0x8045e788;
SECTIONS {
  .text.s8_activate_and_post_800ac278 0x800ac278 : { *(.text.s8_activate_and_post_800ac278) }
  .sdata 0x804ae398 (NOLOAD) : {
    . = 0x0; lbl_804AE398 = .;
    . = 0x10; lbl_804AE3A8 = .;
    . = 0x28; lbl_804AE3C0 = .;
    . = 0x33bc; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

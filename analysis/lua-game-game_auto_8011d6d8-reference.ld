/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8011d6d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8013C9AC = 0x8013c9ac;
fn_8013E3D4 = 0x8013e3d4;
fn_80165254 = 0x80165254;
fn_80178C48 = 0x80178c48;
fn_80178C54 = 0x80178c54;
fn_80178D28 = 0x80178d28;
fn_801817E0 = 0x801817e0;
fn_80181CCC = 0x80181ccc;
SECTIONS {
  .text.w3d_auto_8011d6d8 0x8011d6d8 : { *(.text.w3d_auto_8011d6d8) }
  .text.w3d_auto_8011d6fc 0x8011d6fc : { *(.text.w3d_auto_8011d6fc) }
  .text.w3d_auto_8011d720 0x8011d720 : { *(.text.w3d_auto_8011d720) }
  .text.w3d_auto_8011d744 0x8011d744 : { *(.text.w3d_auto_8011d744) }
  .text.w3d_auto_8011d768 0x8011d768 : { *(.text.w3d_auto_8011d768) }
  .text.w3d_auto_8011d78c 0x8011d78c : { *(.text.w3d_auto_8011d78c) }
  .text.w3d_auto_8011d7d8 0x8011d7d8 : { *(.text.w3d_auto_8011d7d8) }
  .text.w3d_auto_8011d804 0x8011d804 : { *(.text.w3d_auto_8011d804) }
  .text.w3d_auto_8011d850 0x8011d850 : { *(.text.w3d_auto_8011d850) }
  .text.w3d_auto_8011d89c 0x8011d89c : { *(.text.w3d_auto_8011d89c) }
  .text.w3d_auto_8012603c 0x8012603c : { *(.text.w3d_auto_8012603c) }
  .text.w3d_auto_801359c8 0x801359c8 : { *(.text.w3d_auto_801359c8) }
  .text.w3d_auto_80139454 0x80139454 : { *(.text.w3d_auto_80139454) }
  .text.w3d_auto_80139994 0x80139994 : { *(.text.w3d_auto_80139994) }
  .text.w3d_auto_8013c938 0x8013c938 : { *(.text.w3d_auto_8013c938) }
  .sdata 0x804ab078 (NOLOAD) : {
    . = 0x0; lbl_804AB078 = .;
    . = 0x2; lbl_804AB07A = .;
    . = 0x4; lbl_804AB07C = .;
    . = 0x451c; lbl_804AF594 = .;
    . = 0x4520; lbl_804AF598 = .;
    . = 0x4524; lbl_804AF59C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

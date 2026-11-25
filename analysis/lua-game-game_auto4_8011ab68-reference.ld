/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8011ab68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC6DC = 0x800fc6dc;
fn_8011AE58 = 0x8011ae58;
fn_8011AF40 = 0x8011af40;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8021A768 = 0x8021a768;
fn_8021A9DC = 0x8021a9dc;
fn_8021B00C = 0x8021b00c;
fn_8021CC78 = 0x8021cc78;
fn_8021D928 = 0x8021d928;
fn_8021DD04 = 0x8021dd04;
fn_8025D588 = 0x8025d588;
SECTIONS {
  .text.w3d_auto_8011ab68 0x8011ab68 : { *(.text.w3d_auto_8011ab68) }
  .text.w3d_auto_8013fecc 0x8013fecc : { *(.text.w3d_auto_8013fecc) }
  .text.w3d_auto_8015fb34 0x8015fb34 : { *(.text.w3d_auto_8015fb34) }
  .text.w3d_auto_8021b010 0x8021b010 : { *(.text.w3d_auto_8021b010) }
  .text.w3d_auto_8025bb98 0x8025bb98 : { *(.text.w3d_auto_8025bb98) }
  .sdata 0x804af3a8 (NOLOAD) : {
    . = 0x0; lbl_804AF3A8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

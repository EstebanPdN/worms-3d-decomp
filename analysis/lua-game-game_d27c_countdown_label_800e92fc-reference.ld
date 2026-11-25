/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_countdown_label_800e92fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ceil_802e85fc = 0x802e85fc;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
fmt_8038b264 = 0x8038b264;
format_803434d4 = 0x803434d4;
norm_801f6c2c = 0x801f6c2c;
props_8011adf8 = 0x8011adf8;
value_80178df0 = 0x80178df0;
visible_8011afac = 0x8011afac;
SECTIONS {
  .text.d27c_countdown_label_800e92fc 0x800e92fc : { *(.text.d27c_countdown_label_800e92fc) }
  .rodata 0x8038b268 : { *(.rodata) }
  .sdata 0x804aee50 (NOLOAD) : {
    . = 0x0; colorA_804aee50 = .;
    . = 0x4; colorB_804aee54 = .;
    . = 0x564; propKey_804af3b4 = .;
    . = 0x2938; svc_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

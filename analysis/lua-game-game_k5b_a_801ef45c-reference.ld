/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_field_types_sinit_801ef45c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_802097ecPCcii = 0x802097ec;
lbl_803b0d2c = 0x803b0d2c;
lbl_803b0d34 = 0x803b0d34;
lbl_803b0d3c = 0x803b0d3c;
lbl_80417730 = 0x80417730;
lbl_80417748 = 0x80417748;
lbl_80417760 = 0x80417760;
lbl_8045e124 = 0x8045e124;
lbl_8045e14c = 0x8045e14c;
lbl_8045e164 = 0x8045e164;
w3d_auto_801edbd4 = 0x801edbd4;
w3d_auto_801edc28 = 0x801edc28;
w3d_auto_801ede78 = 0x801ede78;
w3d_k5b_shared_defaults_create_801edab8 = 0x801edab8;
w3d_s21_insert_sorted_80200af8 = 0x80200af8;
SECTIONS {
  .text.w3d_k5b_field_types_sinit_801ef45c 0x801ef45c : { *(.text.w3d_k5b_field_types_sinit_801ef45c) }
  .sdata 0x804b0590 (NOLOAD) : {
    . = 0x0; lbl_804b0590 = .;
    . = 0x4; lbl_804b0594 = .;
    . = 0x8; lbl_804b0598 = .;
    . = 0xc; lbl_804b059c = .;
    . = 0x10; lbl_804b05a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29b_box_set_80090f84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804336a0 = 0x804336a0;
lbl_804336ac = 0x804336ac;
lbl_804336b8 = 0x804336b8;
lbl_804336c4 = 0x804336c4;
lbl_804336d0 = 0x804336d0;
lbl_804336dc = 0x804336dc;
lbl_804336e8 = 0x804336e8;
lbl_804336f4 = 0x804336f4;
lbl_80433700 = 0x80433700;
lbl_8043370c = 0x8043370c;
lbl_80433718 = 0x80433718;
lbl_80433724 = 0x80433724;
lbl_80433730 = 0x80433730;
lbl_8043373c = 0x8043373c;
lbl_80433748 = 0x80433748;
lbl_80433754 = 0x80433754;
w3d_box_update_80090dac = 0x80090dac;
w3d_record12_at_80343bb4 = 0x80343bb4;
w3d_set_pos_801f77f4 = 0x801f77f4;
SECTIONS {
  .text.w3d_d29b_box_set_80090f84 0x80090f84 : { *(.text.w3d_d29b_box_set_80090f84) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; lbl_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

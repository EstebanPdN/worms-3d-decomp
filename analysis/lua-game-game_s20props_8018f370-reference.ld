/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_8018f370)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb834 = 0x801eb834;
fn_801eff8c = 0x801eff8c;
lbl_803a80fc = 0x803a80fc;
lbl_803a8124 = 0x803a8124;
lbl_803a8134 = 0x803a8134;
lbl_803a8144 = 0x803a8144;
lbl_803a8154 = 0x803a8154;
lbl_803a8164 = 0x803a8164;
lbl_803a8174 = 0x803a8174;
lbl_803a8188 = 0x803a8188;
lbl_803a81a0 = 0x803a81a0;
lbl_803fe470 = 0x803fe470;
lbl_803fe47c = 0x803fe47c;
lbl_803fe488 = 0x803fe488;
lbl_803fe494 = 0x803fe494;
lbl_803fe4a0 = 0x803fe4a0;
lbl_803fe4ac = 0x803fe4ac;
lbl_803fe4b8 = 0x803fe4b8;
lbl_804597bc = 0x804597bc;
lbl_804597d0 = 0x804597d0;
lbl_804597e4 = 0x804597e4;
lbl_804597f8 = 0x804597f8;
lbl_8045980c = 0x8045980c;
lbl_80459820 = 0x80459820;
lbl_80459834 = 0x80459834;
lbl_80459848 = 0x80459848;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_8018f370 0x8018f370 : { *(.text.w3d_s20_register_properties_8018f370) }
  .sdata 0x804b0284 (NOLOAD) : {
    . = 0x0; lbl_804b0284 = .;
    . = 0x4; lbl_804b0288 = .;
    . = 0x8; lbl_804b028c = .;
    . = 0xc; lbl_804b0290 = .;
    . = 0x10; lbl_804b0294 = .;
    . = 0x14; lbl_804b0298 = .;
    . = 0x18; lbl_804b029c = .;
    . = 0x1c; lbl_804b02a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

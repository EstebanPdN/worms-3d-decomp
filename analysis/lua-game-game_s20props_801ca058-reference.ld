/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801ca058)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ec52c = 0x801ec52c;
fn_801ecc6c = 0x801ecc6c;
fn_801eff8c = 0x801eff8c;
lbl_803ad854 = 0x803ad854;
lbl_803adb34 = 0x803adb34;
lbl_803adb58 = 0x803adb58;
lbl_803adb88 = 0x803adb88;
lbl_803adbbc = 0x803adbbc;
lbl_803adbf4 = 0x803adbf4;
lbl_803adc2c = 0x803adc2c;
lbl_803adc60 = 0x803adc60;
lbl_803fe630 = 0x803fe630;
lbl_8045d688 = 0x8045d688;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801ca058 0x801ca058 : { *(.text.w3d_s20_register_properties_801ca058) }
  .sdata 0x804b04ec (NOLOAD) : {
    . = 0x0; lbl_804b04ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

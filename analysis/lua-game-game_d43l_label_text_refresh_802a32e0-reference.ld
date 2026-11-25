/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d43l_label_text_refresh_802a32e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
__3StrPCc = 0x8020bb54;
fn_800fc2b0 = 0x800fc2b0;
fn_8015adf4 = 0x8015adf4;
fn_8018c5b0 = 0x8018c5b0;
fn_8018d324 = 0x8018d324;
fn_8018d35c = 0x8018d35c;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_8020bf2c = 0x8020bf2c;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802a36cc = 0x802a36cc;
fn_802b1880 = 0x802b1880;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343580 = 0x80343580;
gt_803d2e2c = 0x803d2e2c;
lt_803d2e28 = 0x803d2e28;
SECTIONS {
  .text.d43l_label_text_refresh_802a32e0 0x802a32e0 : { *(.text.d43l_label_text_refresh_802a32e0) }
  .rodata 0x803d2e30 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

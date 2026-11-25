/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_light_new_800c07c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020b680 = 0x8020b680;
fn_80212fd4 = 0x80212fd4;
fn_802134fc = 0x802134fc;
fn_802eee50 = 0x802eee50;
fn_803413d8 = 0x803413d8;
fn_803442b4 = 0x803442b4;
lbl_80382f88 = 0x80382f88;
lbl_80414a90 = 0x80414a90;
lbl_8043c384 = 0x8043c384;
lbl_8043c394 = 0x8043c394;
lbl_8043c3a0 = 0x8043c3a0;
lbl_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d25h_light_new_800c07c4 0x800c07c4 : { *(.text.w3d_d25h_light_new_800c07c4) }
  .rodata 0x80382fa4 : { *(.rodata) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; lbl_804aada8 = .;
    . = 0x69e0; lbl_804b1788 = .;
    . = 0x6a44; lbl_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

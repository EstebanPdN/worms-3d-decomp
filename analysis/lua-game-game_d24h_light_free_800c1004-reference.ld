/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_light_free_800c1004)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80212fd4 = 0x80212fd4;
fn_802134fc = 0x802134fc;
fn_802eee50 = 0x802eee50;
fn_803442b4 = 0x803442b4;
lbl_80382f88 = 0x80382f88;
lbl_8043c384 = 0x8043c384;
lbl_8043c394 = 0x8043c394;
lbl_8043c3a0 = 0x8043c3a0;
SECTIONS {
  .text.w3d_d24h_light_free_800c1004 0x800c1004 : { *(.text.w3d_d24h_light_free_800c1004) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; lbl_804aada8 = .;
    . = 0x6a44; lbl_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

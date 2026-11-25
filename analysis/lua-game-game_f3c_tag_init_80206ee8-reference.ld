/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f3c_tag_init_80206ee8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80207490 = 0x80207490;
fn_802109dc = 0x802109dc;
fn_80212fd4 = 0x80212fd4;
fn_802134fc = 0x802134fc;
fn_802eee50 = 0x802eee50;
lbl_804191c0 = 0x804191c0;
lbl_80419200 = 0x80419200;
SECTIONS {
  .text.f3c_tag_init_80206ee8 0x80206ee8 : { *(.text.f3c_tag_init_80206ee8) }
  .sdata 0x804b18f0 (NOLOAD) : {
    . = 0x0; lbl_804b18f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

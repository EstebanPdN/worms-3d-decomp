/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f3c_tag_init_801db144)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801de524 = 0x801de524;
fn_8020b680 = 0x8020b680;
fn_802109dc = 0x802109dc;
fn_802ee7d0 = 0x802ee7d0;
lbl_803afe38 = 0x803afe38;
lbl_804168c0 = 0x804168c0;
lbl_80416970 = 0x80416970;
lbl_80416ae8 = 0x80416ae8;
SECTIONS {
  .text.f3c_tag_init_801db144 0x801db144 : { *(.text.f3c_tag_init_801db144) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; lbl_804ab80c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc31b_promote_endpoint_802cccbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802cc01c = 0x802cc01c;
fn_802cce78 = 0x802cce78;
lbl_80473724 = 0x80473724;
lbl_80473764 = 0x80473764;
lbl_804738a4 = 0x804738a4;
lbl_804a9cf8 = 0x804a9cf8;
SECTIONS {
  .text.w3d_cc31b_promote_endpoint_802cccbc 0x802cccbc : { *(.text.w3d_cc31b_promote_endpoint_802cccbc) }
  .sdata 0x804abcc4 (NOLOAD) : {
    . = 0x0; lbl_804abcc4 = .;
    . = 0x20; lbl_804abce4 = .;
    . = 0x24; lbl_804abce8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

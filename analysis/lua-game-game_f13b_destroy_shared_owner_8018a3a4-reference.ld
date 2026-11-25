/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f13b_destroy_8018a3a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190384 = 0x80190384;
fn_801fe240 = 0x801fe240;
vt_80412ee0 = 0x80412ee0;
SECTIONS {
  .text.f13b_destroy_8018a3a4 0x8018a3a4 : { *(.text.f13b_destroy_8018a3a4) }
  .sdata 0x804b0238 (NOLOAD) : {
    . = 0x0; lbl_804b0238 = .;
    . = 0x4; lbl_804b023c = .;
    . = 0x8; lbl_804b0240 = .;
    . = 0xc; lbl_804b0244 = .;
    . = 0x10; lbl_804b0248 = .;
    . = 0x14; lbl_804b024c = .;
    . = 0x18; lbl_804b0250 = .;
    . = 0x1c; lbl_804b0254 = .;
    . = 0x20; lbl_804b0258 = .;
    . = 0x24; lbl_804b025c = .;
    . = 0x28; lbl_804b0260 = .;
    . = 0x2c; lbl_804b0264 = .;
    . = 0x30; lbl_804b0268 = .;
    . = 0x34; lbl_804b026c = .;
    . = 0x1670; lbl_804b18a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

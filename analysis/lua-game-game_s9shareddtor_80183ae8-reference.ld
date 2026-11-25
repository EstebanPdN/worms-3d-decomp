/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_destroy_resource_set_80183ae8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190384 = 0x80190384;
lbl_80412bc8 = 0x80412bc8;
SECTIONS {
  .text.s9_destroy_resource_set_80183ae8 0x80183ae8 : { *(.text.s9_destroy_resource_set_80183ae8) }
  .sdata 0x804ab660 (NOLOAD) : {
    . = 0x0; lbl_804ab660 = .;
    . = 0x4b74; lbl_804b01d4 = .;
    . = 0x4b78; lbl_804b01d8 = .;
    . = 0x4b7c; lbl_804b01dc = .;
    . = 0x4b80; lbl_804b01e0 = .;
    . = 0x4b84; lbl_804b01e4 = .;
    . = 0x4b88; lbl_804b01e8 = .;
    . = 0x4b8c; lbl_804b01ec = .;
    . = 0x4b90; lbl_804b01f0 = .;
    . = 0x4b94; lbl_804b01f4 = .;
    . = 0x4b98; lbl_804b01f8 = .;
    . = 0x4b9c; lbl_804b01fc = .;
    . = 0x4ba0; lbl_804b0200 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

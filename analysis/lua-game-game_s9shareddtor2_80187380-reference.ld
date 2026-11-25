/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_destroy_resource_set_80187380)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80190384 = 0x80190384;
lbl_80412da8 = 0x80412da8;
SECTIONS {
  .text.s9_destroy_resource_set_80187380 0x80187380 : { *(.text.s9_destroy_resource_set_80187380) }
  .sdata 0x804ab688 (NOLOAD) : {
    . = 0x0; lbl_804ab688 = .;
    . = 0x4b7c; lbl_804b0204 = .;
    . = 0x4b80; lbl_804b0208 = .;
    . = 0x4b84; lbl_804b020c = .;
    . = 0x4b88; lbl_804b0210 = .;
    . = 0x4b8c; lbl_804b0214 = .;
    . = 0x4b90; lbl_804b0218 = .;
    . = 0x4b94; lbl_804b021c = .;
    . = 0x4b98; lbl_804b0220 = .;
    . = 0x4b9c; lbl_804b0224 = .;
    . = 0x4ba0; lbl_804b0228 = .;
    . = 0x4ba4; lbl_804b022c = .;
    . = 0x4ba8; lbl_804b0230 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

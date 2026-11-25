/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_handle_key_80277a10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80275f18 = 0x80275f18;
fn_802761b8 = 0x802761b8;
fn_802ef198 = 0x802ef198;
SECTIONS {
  .text.w3d_handle_key_80277a10 0x80277a10 : { *(.text.w3d_handle_key_80277a10) }
  .sdata 0x804abb9c (NOLOAD) : {
    . = 0x0; lbl_804abb9c = .;
    . = 0x4; lbl_804abba0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

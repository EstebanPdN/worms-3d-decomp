/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18b_register_array_80250378)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
lbl_803c59d8 = 0x803c59d8;
lbl_8045ed1c = 0x8045ed1c;
lbl_80465030 = 0x80465030;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc18b_register_array_80250378 0x80250378 : { *(.text.w3d_cc18b_register_array_80250378) }
  .sdata 0x804b0904 (NOLOAD) : {
    . = 0x0; lbl_804b0904 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

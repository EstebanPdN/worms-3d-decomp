/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_register_stack_80225fc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801efff0 = 0x801efff0;
lbl_803b7e8c = 0x803b7e8c;
lbl_803b7e9c = 0x803b7e9c;
lbl_8045ed94 = 0x8045ed94;
lbl_80464a40 = 0x80464a40;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc17c_register_stack_80225fc4 0x80225fc4 : { *(.text.w3d_cc17c_register_stack_80225fc4) }
  .sdata 0x804b07d8 (NOLOAD) : {
    . = 0x0; lbl_804b07d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

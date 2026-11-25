/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_initialize_interfaces_801c23e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801b529c = 0x801b529c;
lbl_80414d30 = 0x80414d30;
SECTIONS {
  .text.w3d_s12_initialize_interfaces_801c23e4 0x801c23e4 : { *(.text.w3d_s12_initialize_interfaces_801c23e4) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

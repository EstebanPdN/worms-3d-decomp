/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_initialize_interfaces_801cab48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801c90c0 = 0x801c90c0;
lbl_80416280 = 0x80416280;
SECTIONS {
  .text.w3d_s12_initialize_interfaces_801cab48 0x801cab48 : { *(.text.w3d_s12_initialize_interfaces_801cab48) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x4; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

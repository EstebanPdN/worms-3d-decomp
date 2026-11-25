/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_initialize_interfaces_8019b6f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
lbl_80413530 = 0x80413530;
SECTIONS {
  .text.w3d_s12_initialize_interfaces_8019b6f0 0x8019b6f0 : { *(.text.w3d_s12_initialize_interfaces_8019b6f0) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x8; lbl_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_destroy_buffers_8016fa94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1f8 = 0x801fe1f8;
fn_801fe2e0 = 0x801fe2e0;
SECTIONS {
  .text.w3d_s20_destroy_buffers_8016fa94 0x8016fa94 : { *(.text.w3d_s20_destroy_buffers_8016fa94) }
  .text.w3d_s20_destroy_owned_80178474 0x80178474 : { *(.text.w3d_s20_destroy_owned_80178474) }
  .sdata 0x804b1894 (NOLOAD) : {
    . = 0x0; lbl_804b1894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

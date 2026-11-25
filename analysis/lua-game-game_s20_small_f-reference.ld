/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_publish_current_801673f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016ee10 = 0x8016ee10;
SECTIONS {
  .text.w3d_s20_publish_current_801673f0 0x801673f0 : { *(.text.w3d_s20_publish_current_801673f0) }
  .text.w3d_s20_dispatch_target_801a3b58 0x801a3b58 : { *(.text.w3d_s20_dispatch_target_801a3b58) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . = 0x4; lbl_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

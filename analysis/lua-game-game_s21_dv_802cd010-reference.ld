/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_shutdown_handles_802cd010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802cce78 = 0x802cce78;
lbl_80473764 = 0x80473764;
SECTIONS {
  .text.w3d_s21_shutdown_handles_802cd010 0x802cd010 : { *(.text.w3d_s21_shutdown_handles_802cd010) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . = 0x4; lbl_804abce8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

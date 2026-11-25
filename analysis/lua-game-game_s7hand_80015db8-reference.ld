/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80015db8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80015264 = 0x80015264;
fn_80015E64 = 0x80015e64;
fn_802134FC = 0x802134fc;
SECTIONS {
  .text.w3d_auto_80015db8 0x80015db8 : { *(.text.w3d_auto_80015db8) }
  .sdata 0x804aa6f8 (NOLOAD) : {
    . = 0x0; lbl_804AA6F8 = .;
    . = 0x4; lbl_804AA6FC = .;
    . = 0x8; lbl_804AA700 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

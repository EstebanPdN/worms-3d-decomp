/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c30_record_80207b30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80207a58 = 0x80207a58;
fn_802eee50 = 0x802eee50;
fn_802ef9c0 = 0x802ef9c0;
w3d_copy_802eee50 = 0x802eee50;
SECTIONS {
  .text.tsonnet_c30_record_80207b30 0x80207b30 : { *(.text.tsonnet_c30_record_80207b30) }
  .sdata 0x804b0660 (NOLOAD) : {
    . = 0x0; lbl_804b0660 = .;
    . = 0x4; lbl_804b0664 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

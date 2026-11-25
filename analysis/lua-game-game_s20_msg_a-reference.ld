/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_reset_with_message_80156190)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015884c = 0x8015884c;
fn_8015f5a0 = 0x8015f5a0;
fn_8015fc58 = 0x8015fc58;
fn_801613f0 = 0x801613f0;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_s20_reset_with_message_80156190 0x80156190 : { *(.text.w3d_s20_reset_with_message_80156190) }
  .sdata 0x804afe70 (NOLOAD) : {
    . = 0x0; lbl_804afe70 = .;
    . = 0x18e4; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

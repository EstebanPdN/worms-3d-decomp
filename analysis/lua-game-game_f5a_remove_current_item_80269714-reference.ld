/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f5a_remove_current_item_80269714)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fd1c = 0x8015fd1c;
fn_8026d850 = 0x8026d850;
fn_8026d8e8 = 0x8026d8e8;
fn_802b1f98 = 0x802b1f98;
SECTIONS {
  .text.w3d_f5a_remove_current_item_80269714 0x80269714 : { *(.text.w3d_f5a_remove_current_item_80269714) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; instance_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f9a_card_read_80289088)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20F9aCardText_8020bb54PCc = 0x8020bb54;
fn_8015adf4 = 0x8015adf4;
fn_80174074 = 0x80174074;
fn_8020b680 = 0x8020b680;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
type_80413db0 = 0x80413db0;
SECTIONS {
  .text.w3d_f9a_card_read_80289088 0x80289088 : { *(.text.w3d_f9a_card_read_80289088) }
  .sdata 0x804b195c (NOLOAD) : {
    . = 0x0; tint_804b195c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

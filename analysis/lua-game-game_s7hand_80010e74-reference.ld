/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80010e74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8000B2F8 = 0x8000b2f8;
fn_8000B4C4 = 0x8000b4c4;
fn_8000B5F4 = 0x8000b5f4;
fn_8000B7DC = 0x8000b7dc;
fn_80010F60 = 0x80010f60;
fn_80010F9C = 0x80010f9c;
fn_80010FC4 = 0x80010fc4;
SECTIONS {
  .text.w3d_auto_80010e74 0x80010e74 : { *(.text.w3d_auto_80010e74) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804AA6D8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

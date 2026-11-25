/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f14c_editor_key_80277494)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_80271518 = 0x80271518;
fn_80271c94 = 0x80271c94;
fn_80275cdc = 0x80275cdc;
fn_80275f18 = 0x80275f18;
fn_8027a98c = 0x8027a98c;
fn_802ef198 = 0x802ef198;
SECTIONS {
  .text.w3d_f14c_editor_key_80277494 0x80277494 : { *(.text.w3d_f14c_editor_key_80277494) }
  .sdata 0x804abb9c (NOLOAD) : {
    . = 0x0; keys_804abb9c = .;
    . = 0x4; keys_804abba0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

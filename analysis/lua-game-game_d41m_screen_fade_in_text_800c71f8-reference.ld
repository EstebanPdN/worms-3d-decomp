/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41m_screen_fade_in_text_800c71f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c7944 = 0x800c7944;
fn_800c7c84 = 0x800c7c84;
fn_800fde38 = 0x800fde38;
fn_80173df0 = 0x80173df0;
fn_8018c5b0 = 0x8018c5b0;
fn_8018d35c = 0x8018d35c;
fn_8018d434 = 0x8018d434;
fn_8034357c = 0x8034357c;
fn_80343580 = 0x80343580;
string_ctor_8020bb54 = 0x8020bb54;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d41m_screen_fade_in_text_800c71f8 0x800c71f8 : { *(.text.d41m_screen_fade_in_text_800c71f8) }
  .rodata 0x803879e8 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

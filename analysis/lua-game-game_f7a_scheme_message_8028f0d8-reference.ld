/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f7a_scheme_message_8028f0d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16F7aText_8020bb54PCc = 0x8020bb54;
fn_8010a8fc = 0x8010a8fc;
fn_8015f65c = 0x8015f65c;
fn_8016293c = 0x8016293c;
fn_8028f338 = 0x8028f338;
fn_8028f4a0 = 0x8028f4a0;
fn_8028f4ac = 0x8028f4ac;
fn_8028fb10 = 0x8028fb10;
fn_80290204 = 0x80290204;
fn_80290d50 = 0x80290d50;
fn_80291b90 = 0x80291b90;
fn_802924e4 = 0x802924e4;
fn_80292818 = 0x80292818;
fn_80292d4c = 0x80292d4c;
fn_8029301c = 0x8029301c;
fn_80293020 = 0x80293020;
fn_802ef234 = 0x802ef234;
full_803d0148 = 0x803d0148;
SECTIONS {
  .text.w3d_f7a_scheme_message_8028f0d8 0x8028f0d8 : { *(.text.w3d_f7a_scheme_message_8028f0d8) }
  .sdata 0x804b0cfc (NOLOAD) : {
    . = 0x0; cache_804b0cfc = .;
    . = 0x8; cache_804b0d04 = .;
    . = 0x10; cache_804b0d0c = .;
    . = 0x18; cache_804b0d14 = .;
    . = 0x20; cache_804b0d1c = .;
    . = 0x28; cache_804b0d24 = .;
    . = 0x30; cache_804b0d2c = .;
    . = 0x38; cache_804b0d34 = .;
    . = 0x40; cache_804b0d3c = .;
    . = 0x48; cache_804b0d44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

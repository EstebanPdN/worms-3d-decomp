/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800a5cd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a5528 = 0x800a5528;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_803607e0 = 0x803607e0;
lbl_80361860 = 0x80361860;
lbl_8038124c = 0x8038124c;
lbl_803e7ea0 = 0x803e7ea0;
SECTIONS {
  .text.s8_static_init_800a5cd0 0x800a5cd0 : { *(.text.s8_static_init_800a5cd0) }
  .sdata 0x804ae278 (NOLOAD) : {
    . = 0x0; lbl_804ae278 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

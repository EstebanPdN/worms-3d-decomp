/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_compare_cached_limit_8014c89c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_8014ca54 = 0x8014ca54;
fn_80178df0 = 0x80178df0;
fn_80342a74 = 0x80342a74;
lbl_803a1230 = 0x803a1230;
SECTIONS {
  .text.s9_compare_cached_limit_8014c89c 0x8014c89c : { *(.text.s9_compare_cached_limit_8014c89c) }
  .sdata 0x804afdf8 (NOLOAD) : {
    . = 0x0; lbl_804afdf8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

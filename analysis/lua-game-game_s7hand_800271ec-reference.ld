/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800271ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80027114 = 0x80027114;
fn_800FC710 = 0x800fc710;
fn_80178474 = 0x80178474;
fn_80178C48 = 0x80178c48;
fn_803426B4 = 0x803426b4;
SECTIONS {
  .text.w3d_auto_800271ec 0x800271ec : { *(.text.w3d_auto_800271ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

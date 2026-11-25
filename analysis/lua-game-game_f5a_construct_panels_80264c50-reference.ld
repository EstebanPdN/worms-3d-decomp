/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f5a_construct_panels_80264c50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15Member_802afb20 = 0x802afb20;
fn_8015fef0 = 0x8015fef0;
vt_8041bc00 = 0x8041bc00;
vt_8041bc50 = 0x8041bc50;
SECTIONS {
  .text.w3d_f5a_construct_panels_80264c50 0x80264c50 : { *(.text.w3d_f5a_construct_panels_80264c50) }
  .rodata 0x803cb558 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

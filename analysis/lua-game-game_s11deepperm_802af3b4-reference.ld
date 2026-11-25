/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802af3b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
fn_802AFB20 = 0x802afb20;
lbl_8041C590 = 0x8041c590;
lbl_8041C5E0 = 0x8041c5e0;
SECTIONS {
  .text.w3d_auto_802af3b4 0x802af3b4 : { *(.text.w3d_auto_802af3b4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

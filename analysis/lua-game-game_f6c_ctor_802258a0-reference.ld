/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f6c_ctor_802258a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
fn_8020c5c0 = 0x8020c5c0;
fn_80341884 = 0x80341884;
lbl_8041a2d0 = 0x8041a2d0;
lbl_804b06a0 = 0x804b06a0;
SECTIONS {
  .text.f6c_ctor_802258a0 0x802258a0 : { *(.text.f6c_ctor_802258a0) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

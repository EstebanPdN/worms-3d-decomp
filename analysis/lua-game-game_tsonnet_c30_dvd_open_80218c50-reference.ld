/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c30_dvd_open_80218c50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80218d10 = 0x80218d10;
fn_802f4ef0 = 0x802f4ef0;
fn_802f51e4 = 0x802f51e4;
fn_802fb7ac = 0x802fb7ac;
SECTIONS {
  .text.tsonnet_c30_dvd_open_80218c50 0x80218c50 : { *(.text.tsonnet_c30_dvd_open_80218c50) }
  .rodata 0x803b38f8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

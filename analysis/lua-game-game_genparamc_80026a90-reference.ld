/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_destroy_interfaces_80026a90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ff2c = 0x8015ff2c;
fn_80161050 = 0x80161050;
lbl_8040e008 = 0x8040e008;
lbl_8040e208 = 0x8040e208;
lbl_8040e650 = 0x8040e650;
SECTIONS {
  .text.w3d_destroy_interfaces_80026a90 0x80026a90 : { *(.text.w3d_destroy_interfaces_80026a90) }
  .text.w3d_destroy_interfaces_800282e4 0x800282e4 : { *(.text.w3d_destroy_interfaces_800282e4) }
  .text.w3d_destroy_interfaces_800379fc 0x800379fc : { *(.text.w3d_destroy_interfaces_800379fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

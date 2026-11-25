/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_land_attach_model_800b87d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
attach_8008e7d4 = 0x8008e7d4;
bounds_800b7ed0 = 0x800b7ed0;
cache_800b8cf0 = 0x800b8cf0;
publish_800bae54 = 0x800bae54;
rebuild_800b8140 = 0x800b8140;
reserve_801ef048 = 0x801ef048;
set_80251398 = 0x80251398;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d31h_land_attach_model_800b87d0 0x800b87d0 : { *(.text.d31h_land_attach_model_800b87d0) }
  .rodata 0x80382520 : { *(.rodata) }
  .sdata 0x804b17e0 (NOLOAD) : {
    . = 0x0; lbl_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

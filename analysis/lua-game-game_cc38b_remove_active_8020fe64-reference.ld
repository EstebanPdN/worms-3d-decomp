/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38b_remove_active_8020fe64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38b_eligible_801fff3c = 0x801fff3c;
cc38b_enabled_8020b458 = 0x8020b458;
cc38b_service_8020b648 = 0x8020b648;
SECTIONS {
  .text.cc38b_remove_active_8020fe64 0x8020fe64 : { *(.text.cc38b_remove_active_8020fe64) }
  .sdata 0x804b1904 (NOLOAD) : {
    . = 0x0; cc38b_special_804b1904 = .;
    . = 0x4; cc38b_normal_804b1908 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

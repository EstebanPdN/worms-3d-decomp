/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38b_activate_pending_8020ff44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38b_eligible_801fff3c = 0x801fff3c;
cc38b_get_service_8020b648 = 0x8020b648;
SECTIONS {
  .text.cc38b_activate_pending_8020ff44 0x8020ff44 : { *(.text.cc38b_activate_pending_8020ff44) }
  .sdata 0x804aba54 (NOLOAD) : {
    . = 0x0; cc38b_service_804aba54 = .;
    . = 0x5eac; cc38b_pending_804b1900 = .;
    . = 0x5eb4; cc38b_active_804b1908 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

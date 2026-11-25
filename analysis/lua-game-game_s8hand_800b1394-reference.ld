/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_acquire_service_800b1394)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020b680 = 0x8020b680;
lbl_8041b598 = 0x8041b598;
SECTIONS {
  .text.s8_acquire_service_800b1394 0x800b1394 : { *(.text.s8_acquire_service_800b1394) }
  .sdata 0x804aaccc (NOLOAD) : {
    . = 0x0; lbl_804aaccc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

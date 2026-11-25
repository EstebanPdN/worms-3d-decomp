/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(h2a_resource_reset_80169f80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aligned_801fe2a8 = 0x801fe2a8;
descriptor_80411a20 = 0x80411a20;
finish_8016808c = 0x8016808c;
manager_8020b648 = 0x8020b648;
reset_8016a1e8 = 0x8016a1e8;
SECTIONS {
  .text.h2a_resource_reset_80169f80 0x80169f80 : { *(.text.h2a_resource_reset_80169f80) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

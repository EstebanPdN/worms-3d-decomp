/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc44a_release_resource_801656d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc44a_enqueue_80166ff8 = 0x80166ff8;
SECTIONS {
  .text.cc44a_release_resource_801656d4 0x801656d4 : { *(.text.cc44a_release_resource_801656d4) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; cc44a_queue_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

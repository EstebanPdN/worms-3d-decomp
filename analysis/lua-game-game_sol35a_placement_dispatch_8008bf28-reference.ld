/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a_placement_dispatch_8008bf28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a_dispatch_80164514 = 0x80164514;
sol35a_placement_offset_80067288 = 0x80067288;
sol35a_placement_target_80067268 = 0x80067268;
sol35a_service_8040ee70 = 0x8040ee70;
sol35a_service_lookup_8020b680 = 0x8020b680;
SECTIONS {
  .text.sol35a_placement_dispatch_8008bf28 0x8008bf28 : { *(.text.sol35a_placement_dispatch_8008bf28) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; sol35a_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

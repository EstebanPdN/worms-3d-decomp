/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_a6_distance_800a1534)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
handle_80178c48 = 0x80178c48;
invert_801f6c2c = 0x801f6c2c;
item_800fc6dc = 0x800fc6dc;
threshold_8038092c = 0x8038092c;
SECTIONS {
  .text.terra_only_a6_distance_800a1534 0x800a1534 : { *(.text.terra_only_a6_distance_800a1534) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

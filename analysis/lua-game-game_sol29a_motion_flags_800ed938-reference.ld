/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol29a_motion_flags_800ed938)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_800ec6a8 = 0x800ec6a8;
lookup_80341584 = 0x80341584;
parameters_801797b4 = 0x801797b4;
SECTIONS {
  .text.sol29a_motion_flags_800ed938 0x800ed938 : { *(.text.sol29a_motion_flags_800ed938) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

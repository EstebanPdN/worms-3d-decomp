/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b_script_construct_800ffe54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b_assign_8020bd38 = 0x8020bd38;
sol35b_base_801628b0 = 0x801628b0;
sol35b_state_8010272c = 0x8010272c;
sol35b_string_803426b8 = 0x803426b8;
sol35b_tag_80207fec = 0x80207fec;
sol35b_vtable_804105f8 = 0x804105f8;
SECTIONS {
  .text.sol35b_script_construct_800ffe54 0x800ffe54 : { *(.text.sol35b_script_construct_800ffe54) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

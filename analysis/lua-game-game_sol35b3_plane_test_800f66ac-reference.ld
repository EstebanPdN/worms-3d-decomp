/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b3_plane_test_800f66ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b3_plane_8038c578 = 0x8038c578;
SECTIONS {
  .text.sol35b3_plane_test_800f66ac 0x800f66ac : { *(.text.sol35b3_plane_test_800f66ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

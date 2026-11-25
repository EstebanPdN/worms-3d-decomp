/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b3_fall_800d6350)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b3_bounds_800d60ac = 0x800d60ac;
sol35b3_down_80388e6c = 0x80388e6c;
sol35b3_limit_80388e74 = 0x80388e74;
sol35b3_remove_8015fd1c = 0x8015fd1c;
sol35b3_step_80388e70 = 0x80388e70;
sol35b3_zero_80388e68 = 0x80388e68;
SECTIONS {
  .text.sol35b3_fall_800d6350 0x800d6350 : { *(.text.sol35b3_fall_800d6350) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

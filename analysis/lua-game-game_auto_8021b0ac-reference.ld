/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8021b0ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021BD4C = 0x8021bd4c;
fn_8021BF14 = 0x8021bf14;
fn_8021C48C = 0x8021c48c;
fn_8021C74C = 0x8021c74c;
SECTIONS {
  .text.w3d_auto_8021b0ac 0x8021b0ac : { *(.text.w3d_auto_8021b0ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

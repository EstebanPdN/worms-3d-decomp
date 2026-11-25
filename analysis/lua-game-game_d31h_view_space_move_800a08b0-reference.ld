/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31h_view_space_move_800a08b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
from44_801f74d0 = 0x801f74d0;
invert_801f76e0 = 0x801f76e0;
solve_800a0fbc = 0x800a0fbc;
SECTIONS {
  .text.d31h_view_space_move_800a08b0 0x800a08b0 : { *(.text.d31h_view_space_move_800a08b0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

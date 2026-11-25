/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_jetpack_state_800ac14c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
strcmp = 0x802ef234;
w3d_auto_800aba08 = 0x800aba08;
w3d_str_80381c08 = 0x80381c08;
w3d_str_80381c48 = 0x80381c48;
w3d_str_80381c58 = 0x80381c58;
SECTIONS {
  .text.w3d_k10a_jetpack_state_800ac14c 0x800ac14c : { *(.text.w3d_k10a_jetpack_state_800ac14c) }
  .rodata 0x80381c60 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_world_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

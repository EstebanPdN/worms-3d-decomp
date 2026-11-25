/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d21b_camera_oscillate_800a439c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d21b_vecA_80438544 = 0x80438544;
d21b_vecB_80438550 = 0x80438550;
d21b_vecC_8043855c = 0x8043855c;
w3d_cx9c_sinf_802e88ac = 0x802e88ac;
w3d_logic_hook_800c88c4 = 0x800c88c4;
SECTIONS {
  .text.d21b_camera_oscillate_800a439c 0x800a439c : { *(.text.d21b_camera_oscillate_800a439c) }
  .rodata 0x80380dc8 : { *(.rodata) }
  .sdata 0x804ae1b0 (NOLOAD) : {
    . = 0x0; d21b_initA_804ae1b0 = .;
    . = 0x4; d21b_initB_804ae1b4 = .;
    . = 0x8; d21b_initC_804ae1b8 = .;
    . = 0x35d8; w3d_context_804b1788 = .;
    . = 0x35e4; w3d_hook_804b1794 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

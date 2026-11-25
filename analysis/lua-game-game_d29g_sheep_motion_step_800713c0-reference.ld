/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_sheep_motion_step_800713c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800715b0 = 0x800715b0;
fn_80071e30 = 0x80071e30;
w3d_auto_801797b4 = 0x801797b4;
w3d_empty_80341584 = 0x80341584;
SECTIONS {
  .text.w3d_d29g_sheep_motion_step_800713c0 0x800713c0 : { *(.text.w3d_d29g_sheep_motion_step_800713c0) }
  .rodata 0x8037caa0 : { *(.rodata) }
  .sdata 0x804aaae8 (NOLOAD) : {
    . = 0x0; debug_804aaae8 = .;
    . = 0x6e5c; step_804b1944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

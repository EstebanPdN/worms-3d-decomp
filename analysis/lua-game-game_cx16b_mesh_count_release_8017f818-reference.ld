/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_mesh_count_release_8017f818)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801801b0 = 0x801801b0;
fn_80190458 = 0x80190458;
lbl_804a89d8 = 0x804a89d8;
SECTIONS {
  .text.w3d_cx16b_mesh_count_release_8017f818 0x8017f818 : { *(.text.w3d_cx16b_mesh_count_release_8017f818) }
  .sdata 0x804ab618 (NOLOAD) : {
    . = 0x0; lbl_804ab618 = .;
    . = 0x4; lbl_804ab61c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_convert_planes_801d8f98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d8cd4 = 0x801d8cd4;
fn_801d8e20 = 0x801d8e20;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_d25e_convert_planes_801d8f98 0x801d8f98 : { *(.text.w3d_d25e_convert_planes_801d8f98) }
  .sdata 0x804b0554 (NOLOAD) : {
    . = 0x0; lbl_804b0554 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

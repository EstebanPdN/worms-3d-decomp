/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_global6_800fdc80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fdcf4 = 0x800fdcf4;
SECTIONS {
  .text.w3d_s20_forward_global6_800fdc80 0x800fdc80 : { *(.text.w3d_s20_forward_global6_800fdc80) }
  .sdata 0x804aaf64 (NOLOAD) : {
    . = 0x0; lbl_804aaf64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

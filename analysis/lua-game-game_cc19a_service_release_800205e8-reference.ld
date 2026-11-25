/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19a_service_release_800205e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800068b0 = 0x800068b0;
fn_801628ec = 0x801628ec;
lbl_8040db08 = 0x8040db08;
SECTIONS {
  .text.w3d_cc19a_service_release_800205e8 0x800205e8 : { *(.text.w3d_cc19a_service_release_800205e8) }
  .sdata 0x804b1760 (NOLOAD) : {
    . = 0x0; lbl_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

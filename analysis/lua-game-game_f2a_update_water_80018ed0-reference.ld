/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f2a_update_water_80018ed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80018f88 = 0x80018f88;
fn_800fc1b0 = 0x800fc1b0;
fn_80178df0 = 0x80178df0;
fn_80342a74 = 0x80342a74;
lbl_8036a8f4 = 0x8036a8f4;
SECTIONS {
  .text.w3d_f2a_update_water_80018ed0 0x80018ed0 : { *(.text.w3d_f2a_update_water_80018ed0) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; lbl_804aa750 = .;
    . = 0x10; lbl_804aa760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

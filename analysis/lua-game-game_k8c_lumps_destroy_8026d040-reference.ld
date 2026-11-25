/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_lumps_destroy_8026d040)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ff2c = 0x8015ff2c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
w3d_vtable_8041bd20 = 0x8041bd20;
SECTIONS {
  .text.w3d_k8c_lumps_destroy_8026d040 0x8026d040 : { *(.text.w3d_k8c_lumps_destroy_8026d040) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; w3d_sdata_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}

/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8b_type_registration_8020ba04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_80463308 = 0x80463308;
descriptor_80463330 = 0x80463330;
fn_80200af8 = 0x80200af8;
fn_8020b9c0 = 0x8020b9c0;
name_803b3160 = 0x803b3160;
SECTIONS {
  .text.w3d_cx8b_type_registration_8020ba04 0x8020ba04 : { *(.text.w3d_cx8b_type_registration_8020ba04) }
  .sdata 0x804b0698 (NOLOAD) : {
    . = 0x0; state_804b0698 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
